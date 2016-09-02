LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := SqliteJNIManager
LOCAL_SRC_FILES := SqliteJNIManager.cpp

include $(BUILD_SHARED_LIBRARY)
