/*
 * Windows wrapper around jni/jni.h.
 *
 * jni/jni.h does `#include "jni_md.h"`, and a quote include looks in the
 * including file's own directory first, so it always picks jni/jni_md.h, the
 * Unix one, where JNIEXPORT is a visibility attribute rather than
 * __declspec(dllexport). Compiling against the JDK's jni.h (as the MSYS build
 * does) sidesteps that because the JDK's win32 jni_md.h is not on the include
 * path; the cross build for Windows/ARM64 has no JDK and includes jni/jni.h
 * directly, and then nothing marks the Java_* functions for export. With
 * -DZSTD_DLL_EXPORT=1 giving the ZSTD_* symbols explicit exports, ld no longer
 * auto-exports the rest either, and the DLL ends up without a single JNI
 * function (1.5.7-19 and 1.5.7-20 shipped like that).
 *
 * Including the Windows jni_md.h first sets _JAVASOFT_JNI_MD_H_, so the include
 * inside jni/jni.h becomes a no-op. This directory comes before jni/ on the
 * include path of the cross build, so <jni.h> resolves here.
 */
#ifndef _ZSTD_JNI_WINDOWS_JNI_H_
#define _ZSTD_JNI_WINDOWS_JNI_H_

#include "jni_md.h"
#include "../../../jni/jni.h"

#endif
