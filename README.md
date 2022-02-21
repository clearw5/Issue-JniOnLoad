# Issue-JniOnLoad

For reporting issue https://issuetracker.google.com/issues/220523932.

## Guide

The core source files are following:

1. [foo.cc](https://github.com/hyb1996/Issue-JniOnLoad/blob/main/app/src/main/cpp/foo.cc), the code of library foo, with no JNI_OnLoad defined.
2. [bar.cc](https://github.com/hyb1996/Issue-JniOnLoad/blob/main/app/src/main/cpp/bar.cc), the code of library bar, a no JNI_OnLoad defined.
3. [CMakeLists.txt](https://github.com/hyb1996/Issue-JniOnLoad/blob/main/app/src/main/cpp/CMakeLists.txt), defines libraries foo, bar the their dependency.
4. [MainActivity](https://github.com/hyb1996/Issue-JniOnLoad/blob/main/app/src/main/java/com/example/foo/MainActivity.kt#L19), load libraries foo and bar.

## Steps to reproduce issue

1. Run the code
2. Click text "CLICK ME TO EXECUTE"
3. You will see the logcat output:

```
2022-02-21 15:38:27.116 12825-12825/com.example.foo D/Bar: JNI_OnLoad: count = 1
2022-02-21 15:38:27.117 12825-12825/com.example.foo D/Bar: JNI_OnLoad: count = 2
2022-02-21 15:38:27.117 12825-12825/com.example.foo D/Foo: call function of library bar: 3
```

which means the JNI_OnLoad of libbar.so was called twice.
