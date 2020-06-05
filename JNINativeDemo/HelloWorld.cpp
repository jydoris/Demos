
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

JNIEXPORT jstring JNICALL Java_com_HelloWorld_queryJobViaName
  (JNIEnv *env, jobject obj, jstring name){
      //Step1: convert from Jstring to C-string
      const char* inName = env->GetStringUTFChars(name, NULL);
      if(nullptr == inName){
        std::cout << "Cannot convert JNI string into C-string(char *)\n";
        return NULL;
      }

      //Step2: call c++ function
      std::string job = recordA.queryJob(inName);
      env->ReleaseStringUTFChars(name, inName); //release resources
      std::cout << "Bridge layer: Get " << inName << "'s job: " << job << std::endl;

      //Step3:convert c++ string to c-string, then to JNI String and return result to java
      return env->NewStringUTF(job.c_str());
  }