LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos/audio/include)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libMyGame

LOCAL_SRC_FILES := $(LOCAL_PATH)/hellocpp/main.cpp \
                   $(LOCAL_PATH)/../../../Classes/AppDelegate.cpp \
                   $(LOCAL_PATH)/../../../Classes/Background.cpp \
                   $(LOCAL_PATH)/../../../Classes/CameraHelper.cpp \
                   $(LOCAL_PATH)/../../../Classes/ContactListener.cpp \
                   $(LOCAL_PATH)/../../../Classes/DebugDraw.cpp \
                   $(LOCAL_PATH)/../../../Classes/FrameCleaner.cpp \
                   $(LOCAL_PATH)/../../../Classes/GameObject.cpp \
                   $(LOCAL_PATH)/../../../Classes/GLES-Render.cpp \
                   $(LOCAL_PATH)/../../../Classes/GlobalSetting.cpp \
                   $(LOCAL_PATH)/../../../Classes/HUD.cpp \
                   $(LOCAL_PATH)/../../../Classes/InputLayer.cpp \
                   $(LOCAL_PATH)/../../../Classes/MainGame.cpp \
                   $(LOCAL_PATH)/../../../Classes/MainHUD.cpp \
                   $(LOCAL_PATH)/../../../Classes/MyPhysicsWorld.cpp \
                   $(LOCAL_PATH)/../../../Classes/MyPoolManager.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlayHUD.cpp \
                   $(LOCAL_PATH)/../../../Classes/ResourceManager.cpp \
                   $(LOCAL_PATH)/../../../Classes/RootScene.cpp \
                   $(LOCAL_PATH)/../../../Classes/SingleTon.cpp \
                   $(LOCAL_PATH)/../../../Classes/World.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
