# il2cpphotfix
一款用于热更unity libil2cpp.so动态库的工具,比起其他通过hook方式实现的优点在于无任何兼容性问题。

## 原理
### libil2cpp.so动态库热更
构造一个libil2cpp.so一样的导出函数的跳板动态库，把所有的函数转发到跳板来，
在跳板里实现加载自定义的libil2cpp.so达到热更目的。

### global-metadata.dat文件热更
加载global-metadata.data是通过函数void* MetadataLoader::LoadMetadataFile(const char* fileName)，
 通过修改修改引擎下的MetadataLoader.cpp，实现读取自定义路径的global-metadata.data达到热更目的。
 
 ## 工程说明
 工程是适配的unity 2018.4，如果需要适配其他版本的unity，请参考il2cpp-api.cpp il2cpp-api.h il2cpp-api-functions.h
 定义该版本的支持函数
