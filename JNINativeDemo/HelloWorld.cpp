
#include "jni.h"
#include "include/com_HelloWorld.h"
#include "record.h"

Record  recordA;

JNIEXPORT void JNICALL Java_com_HelloWorld_hello(JNIEnv *env,jobject obj){
    printf("Hello World!\n");
    recordA.init();
    //recordA.showRecord();
    return;
}

JNIEXPORT void JNICALL Java_com_HelloWorld_setRecordValue
  (JNIEnv *env, jobject obj, jint value){
      recordA.setValue(value);
      return;
  }

JNIEXPORT jint JNICALL Java_com_HelloWorld_getRecordValue
  (JNIEnv *env, jobject obj){
      jint result;
      result = recordA.getValue();
      return result; 
  }