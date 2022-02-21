#include <jni.h>
#include <android/log.h>

extern int functionOfLibraryBar(int a, int b);

extern "C"
JNIEXPORT void JNICALL
Java_com_example_foo_MainActivity_functionOfLibraryFoo(JNIEnv* env, jclass clazz) {
  __android_log_print(ANDROID_LOG_DEBUG, "Foo", "call function of library bar: %d", functionOfLibraryBar(1, 2));
}