
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

JNIEXPORT jstring JNICALL Java_com_HelloWorld_setAges
  (JNIEnv *env, jobject obj, jintArray JNIAges){
    //Step1: convert incoming JNI JNIAges to c's jint[]
    jint *inCArray = env->GetIntArrayElements(JNIAges, NULL);
    if(nullptr == inCArray)
      return env->NewStringUTF("Fail in bridge.");
    
    //Step2: perform intent functions
    std::vector<int> tmpAges;
    jsize length = env->GetArrayLength(JNIAges);
    tmpAges.resize(length);
    std::memcpy(tmpAges.data(), inCArray, length * sizeof(int));
    if(!recordA.setAge(tmpAges))
      return env->NewStringUTF("Fail inner Record."); 
      
    return env->NewStringUTF("Sucess!"); 
  }

JNIEXPORT void JNICALL Java_com_HelloWorld_modifyDataViaName
  (JNIEnv *env, jobject obj, jstring JNIName){
    const char* inName = env->GetStringUTFChars(JNIName, NULL);
    if(nullptr == inName){
      std::cout << "Cannot convert in parameter to proper format(JNI string to c-char).\n";
      return;
    }

    int ID = recordA.getValue();
    std::string job = recordA.queryJob(inName); 
    env->ReleaseStringUTFChars(JNIName, inName);

    // -----set the ID------
    //Step1: get a reference to this object's class 
    jclass thisClass = env->GetObjectClass(obj);

    //Step2: get the Filed ID of the instance variable "ID"
    jfieldID fidID = env->GetFieldID(thisClass, "ID", "I");
    if (nullptr == fidID)
      return;
    
    //Step3: get the int given the Filed ID (could escape this step)
    jint num = env->GetIntField(obj, fidID);
    
    //Step4: set the num
    num = ID;
    env->SetIntField(obj, fidID, num);


    // -----set the Job------
    jfieldID fidJob = env->GetFieldID(thisClass, "job", "Ljava/lang/String;");
    if(nullptr == fidJob)
      return;
    jstring jobInfo = (jstring)env->GetObjectField(obj, fidJob);
    jobInfo = env->NewStringUTF(job.c_str());
    env->SetObjectField(obj, fidJob, jobInfo);

  }