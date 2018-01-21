LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := ndk_file_encrpty
LOCAL_SRC_FILES := ndk_file_encrpty.c

include $(BUILD_SHARED_LIBRARY)
