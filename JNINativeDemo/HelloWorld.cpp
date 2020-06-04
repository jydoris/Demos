
#include "jni.h"
#include "include/com_HelloWorld.h"
#include <stdio.h>
#include "record.h"

Record  recordA;

JNIEXPORT void JNICALL Java_com_HelloWorld_hello(JNIEnv *env,jobject obj){
    printf("Hello World!\n");
    recordA.init();
    //recordA.showRecord();
    return;
}