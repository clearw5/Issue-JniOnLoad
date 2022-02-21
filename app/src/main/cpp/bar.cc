#include <jni.h>
#include <android/log.h>

__attribute__((visibility("default"))) int functionOfLibraryBar(int a, int b) {
  return a + b;
}

jint JNICALL JNI_OnLoad(JavaVM*, void*) {
  static int count = 0;
  count++;
  __android_log_print(ANDROID_LOG_DEBUG, "Bar", "JNI_OnLoad: count = %d", count);
  return JNI_VERSION_1_6;
}

void JNICALL JNI_OnUnload(JavaVM*, void*) {
  static int count = 0;
  count++;
  __android_log_print(ANDROID_LOG_DEBUG, "Bar", "JNI_OnUnload: count = %d", count);
}