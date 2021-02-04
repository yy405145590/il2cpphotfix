package com.ly.update;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;

import com.unity3d.player.UnityPlayer;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.zip.CRC32;
import java.util.zip.CheckedInputStream;
import java.util.zip.Inflater;

import dalvik.system.PathClassLoader;
class E_CPU_ABI
{
    public static int ARM = 0;
    public static int ARM64 = 1;
    public static int X86 = 2;
    public static int X64 = 3;
}
interface HotFixOnFinish
{
    void OnFinish();
}

public class HotFixPlugin {
    static{
        System.loadLibrary("il2cpp");
    }
    //public  static native  int ssss(int a, int b);
    private HotFixOnFinish m_onFinish;

    private float m_downloadPercent = -1;
    public  static native  void Init(String il2cppPath, String metaPath);
    public  static native  int  GetRunningCpuType();
    private Activity m_Activity;
    private static Handler m_handler = new Handler();
    private static int PACKMAGICNUM = 3696542;
    HotFixPlugin(HotFixOnFinish onFinish)
    {
        m_onFinish = onFinish;
    }
    public static boolean fileCopy(String oldFilePath,String newFilePath) throws IOException {
        //获得原文件流
        FileInputStream inputStream = new FileInputStream(new File(oldFilePath));
        byte[] data = new byte[1024];
        //输出流
        FileOutputStream outputStream =new FileOutputStream(new File(newFilePath));
        //开始处理流
        while (inputStream.read(data) != -1) {
            outputStream.write(data);
        }
        inputStream.close();
        outputStream.close();
        return true;
    }

    public  float GetDownloadPercent()
    {
        return  m_downloadPercent;
    }

    void WriteToFile(String filename, byte[] data, int start, int len) throws IOException
    {
        File file = new File(filename);
        if(!file.getParentFile().exists())
        {
            Log.d("YY", filename + " parent dir not exist,create it ");
            file.getParentFile().mkdirs();
        }
        if(file.exists())
        {
            Log.d("YY", filename + " exist,delete it ");
            file.delete();
        }
        FileOutputStream fis = new FileOutputStream(file);
        fis.write(data, start, len);
        fis.flush();
        fis.close();
        Log.d("YY", "WriteToFile: " + filename + " " + "success");
    }

    void RenameFile(String srcName, String dstName)
    {
        File fileSrc = new File(srcName);
        File fileDst = new File(dstName);
        if(fileDst.exists())
        {
            Log.d("YY", "RenameFile: filedst exist " + fileDst + " delete it");
            fileDst.delete();
        }
        if(fileSrc.renameTo(fileDst))
        {
            Log.d("YY", "RenameFile: " + srcName + " to " + dstName + " success");
        }
        else
        {
            Log.d("YY", "RenameFile: " + srcName + " to " + dstName + " failed");
        }
    }
    public static byte[] Decompress(byte[] data) {
        byte[] output = null;
        Inflater decompresser = new Inflater();
        decompresser.reset();
        decompresser.setInput(data);

        ByteArrayOutputStream o = new ByteArrayOutputStream(data.length);
        try {
            byte[] buf = new byte[1024];
            while (!decompresser.finished()) {
                int i = decompresser.inflate(buf);
                o.write(buf, 0, i);
            }
            output = o.toByteArray();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                o.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        decompresser.end();
        return output;
    }

    public void onCreate(Activity activity) {
        m_Activity = activity;
        PathClassLoader clsLoader = (PathClassLoader)UnityPlayer.class.getClassLoader();
        String srcPath = clsLoader.findLibrary("il2cpp_");
        String abiPath = srcPath.substring(srcPath.lastIndexOf("/lib/"));
        String rootUrl = "http://192.168.0.152:9999/SoHotFix";
        int abiType = HotFixPlugin.GetRunningCpuType();
        String dlPath = rootUrl;
        if(abiType == E_CPU_ABI.ARM)
        {
            dlPath += "/armeabi-v7a_libil2cpp.so";
        }
        else if(abiType == E_CPU_ABI.ARM64)
        {
            dlPath += "/arm64-v8a_libil2cpp.so";
        }
        else if(abiType == E_CPU_ABI.X86)
        {
            dlPath += "/x86_libil2cpp.so";
        }
        else
        {
            Log.d("YY", "no find abitype: " + abiType);
        }
        String finalDlPath = dlPath;
        new Thread(new Runnable() {
            @Override
            public void run() {
                Object[] retObj = GetLocalIl2Cpp();
                ByteArrayOutputStream dlStream = DownloadFile(finalDlPath);
                Log.d("YY", "run: uncompress data");
                byte[] so_data = null;
                byte[] meta_data = null;
                try {
                    ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream(dlStream.toByteArray());
                    DataInputStream inputStream = new DataInputStream(byteArrayInputStream);
                    int magic = inputStream.readInt();
                    int so_len = inputStream.readInt();
                    int meta_len = inputStream.readInt();
                    int version = inputStream.readInt();
                    int iscompressed = inputStream.readInt();
                    if((int)retObj[1] >= version)
                    {
                        Log.d("YY", "version failed: " + (int)retObj[1]
                                + " ," + version);
                    }
                    else if(magic != PACKMAGICNUM)
                    {
                        Log.d("YY", "magic check failed: " + magic + " ," + PACKMAGICNUM);
                    }
                    else
                    {
                        so_data = new byte[so_len];
                        inputStream.read(so_data);
                        byte[] tmpMetaData = new byte[meta_len];
                        inputStream.read(tmpMetaData);
                        if(iscompressed == 1)
                        {
                            so_data = Decompress(so_data);
                            meta_data = Decompress(tmpMetaData);
                        }
                        Log.d("YY", "magic: " + magic + " so_len: " +
                                so_len + " meta_len: " + meta_len + " version: " +
                                version + " iscompressed: " + iscompressed);
                    }
                }
                catch (Exception e) {
                    e.printStackTrace();
                }
                byte[] finalSo_data = so_data;
                byte[] finalMeta_data = meta_data;
                m_handler.post(new Runnable() {
                    @Override
                    public void run() {
                        if (finalSo_data != null && finalMeta_data != null) {
                            try {
                                File dstDir = m_Activity.getApplicationContext().getFilesDir();
                                String dstPath = dstDir.getPath() + abiPath;
                                String dstPathBak = dstPath + "_bak";
                                WriteToFile(dstPathBak, finalSo_data, 0, finalSo_data.length);

                                //update meta file
                                String dstMetaPath = dstDir.getPath() + "/global-metadata.dat";
                                String dstMetaPathbak = dstMetaPath + "_bak";
                                WriteToFile(dstMetaPathbak, finalMeta_data, 0, finalMeta_data.length);
                                RenameFile(dstPathBak, dstPath);
                                RenameFile(dstMetaPathbak, dstMetaPath);

                                //HotFixPlugin.Init(dstPath, dstMetaPath);
                            } catch (Exception e) {
                                e.printStackTrace();

                                //String dstPath = clsLoader.findLibrary("il2cpp_");
                                //Log.e("YY", "update failed load package so:" + dstPath);
                                //HotFixPlugin.Init(dstPath, null);
                            }
                        } else {
                            //String dstPath = clsLoader.findLibrary("il2cpp_");
                            //Log.e("YY", "can not find any update load package so:" + dstPath);
                            //HotFixPlugin.Init(dstPath, null);
                        }
                        OnFinish();
                    }
                });
            }
        }).start();
    }

    ByteArrayOutputStream DownloadFile(String strUrl)
    {
        Log.d("YY", "DownloadFile:" + strUrl);
        ByteArrayOutputStream outputStream = null;
        try
        {
            URL url = new URL(strUrl);
            HttpURLConnection conn = (HttpURLConnection) url.openConnection();
            conn.setConnectTimeout(30000);
            conn.setReadTimeout(30000);
            conn.setRequestMethod("GET");
            conn.connect();
            int fileOfLength = conn.getContentLength();
            float totallength = 0;
            outputStream = new ByteArrayOutputStream();
            InputStream in = conn.getInputStream();
            byte[] buff = new byte[1024 * 1024];
            int length = 0;
            while ((length = in.read(buff)) > 0)
            {
                totallength += length;
                m_downloadPercent = totallength / fileOfLength;
                outputStream.write(buff, 0, length);
            }
            in.close();
            outputStream.flush();
        }
        catch (Exception e)
        {
            e.printStackTrace();
            outputStream = null;
        }

        return outputStream;
    }

    long GetCrc(String filename)
    {

        CheckedInputStream cis = null;
        try {
            cis = new CheckedInputStream(new FileInputStream(filename),
                    new CRC32());

            byte[] buf = new byte[1024 * 1024];
            while (cis.read(buf) != -1) {
            }
            long crc = cis.getChecksum().getValue();
            Log.d("YY", "GetCrc " + crc + ": " + filename);
            return  crc;
        } catch (Exception e) {
            e.printStackTrace();
        }
        Log.d("YY", "GetCrc 0: " + filename);
        return 0;
    }

    int GetIl2CppVersion(String filename, String metaFilename)
    {
        int updatedVersion = 0;
        try
        {
            File f1 = new File(filename);
            if(f1.exists())
            {
                FileInputStream fileInputStream = new FileInputStream(filename);
                DataInputStream dataInputStream = new DataInputStream(fileInputStream);
                Log.d("YY", "dataInputStream.available()" + dataInputStream.available()
                        + "fileInputStream.available()" + fileInputStream.available());
                dataInputStream.skipBytes(dataInputStream.available() - 16);
                int magic = dataInputStream.readInt();
                int so_crc = dataInputStream.readInt();
                int meta_crc = dataInputStream.readInt();
                int version = dataInputStream.readInt();
                Log.d("YY", "GetIl2CppVersion: magic " + magic +" so_crc " + so_crc
                        + " meta_crc " + meta_crc + " version" + version);
                long crc = meta_crc &0x0FFFFFFFFl;
                if(magic == PACKMAGICNUM)
                {
                    if(metaFilename != null && !metaFilename.isEmpty())
                    {
                        long mycrc = GetCrc(metaFilename);
                        if(crc != mycrc)
                        {
                            Log.d("YY", "GetLocalIl2Cpp: meta crc check failed:" + crc +','
                                    + mycrc + " filename:" + filename);
                        }
                        else
                        {
                            Log.d("YY", "GetLocalIl2Cpp: version "
                                    + version + ", filename " + filename);
                            updatedVersion = version;
                        }
                    }
                }
                else
                {
                    Log.d("YY", "GetLocalIl2Cpp: magic "
                            + magic + ", " + PACKMAGICNUM + " filename:" + filename);
                }
            }
            else
            {
                Log.d("YY", "GetLocalIl2Cpp: filename: "
                        + filename + " not exist");
            }

        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        return updatedVersion;
    }

    Object[] GetLocalIl2Cpp()
    {
        Object[] retObj = new Object[3];
        PathClassLoader clsLoader = (PathClassLoader)UnityPlayer.class.getClassLoader();
        String localPath = clsLoader.findLibrary("il2cpp_");
        String abiPath = localPath.substring(localPath.lastIndexOf("/lib/"));
        File dstDir = m_Activity.getApplicationContext().getFilesDir();
        String il2cppUpdatedPath = dstDir.getPath() + abiPath;
        String metaPathUpdatedPath = dstDir.getPath() + "/global-metadata.dat";
        int updatedVersion = GetIl2CppVersion(il2cppUpdatedPath, metaPathUpdatedPath);
        int localVersion = GetIl2CppVersion(localPath, null);
        if(updatedVersion > localVersion)
        {
            retObj[0] = il2cppUpdatedPath;
            retObj[1] = updatedVersion;
            retObj[2] = metaPathUpdatedPath;
        }
        else
        {
            retObj[0] = localPath;
            retObj[1] = updatedVersion;
            retObj[2] = null;
        }
        return  retObj;
    }

    void LoadIl2Cpp()
    {
        Object[] retObj = GetLocalIl2Cpp();
        Log.d("YY", "LoadIl2Cpp:" + retObj);
        HotFixPlugin.Init((String)retObj[0], retObj[2] != null ? ((String)retObj[2]) : null);
    }
    void OnFinish()
    {
        LoadIl2Cpp();
        m_onFinish.OnFinish();
    }
}
