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
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.List;
import java.util.zip.CheckedInputStream;
import java.util.zip.Inflater;
import java.util.zip.CRC32;

import dalvik.system.PathClassLoader;

public class HotFixActivity extends Activity {
    private HotFixPlugin m_hotFix;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_hot_fix);
        m_hotFix = new HotFixPlugin(new HotFixOnFinish()
        {
            @Override
            public void OnFinish() {
                StartUnity();
            }
        });
        m_hotFix.onCreate(this);
    }

    void StartUnity()
    {
        Intent intent = new Intent(HotFixActivity.this, UnityPlayerActivity.class);
        Bundle extras = getIntent().getExtras();
        if (extras != null)
            intent.putExtras(extras);
        startActivity(intent);
        overridePendingTransition(0, 0);
        finish();
    }
}
