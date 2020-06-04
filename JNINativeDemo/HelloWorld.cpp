
#include "jni.h"
#include "include/com_HelloWorld.h"
#include <stdio.h>
#include "record.h"
JNIEXPORT void JNICALL Java_com_HelloWorld_hello(JNIEnv *env,jobject obj){
    printf("Hello World!\n");
    Record  recordA;
    recordA.init();
    recordA.showRecord();
    return;
}