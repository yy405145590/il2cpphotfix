LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_LDLIBS :=-ldl -llog
LOCAL_MODULE := il2cpp
LOCAL_SRC_FILES := Il2CppHotFix.cpp il2cpp-api.cpp

include $(BUILD_SHARED_LIBRARY)