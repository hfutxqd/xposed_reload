LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := xposed_reload
LOCAL_SRC_FILES := main.c
LOCAL_CPPFLAGS := -std=gnu++0x -Wall -fPIE
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog -fPIE -pie

include $(BUILD_EXECUTABLE)