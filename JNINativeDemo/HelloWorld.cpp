
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


  JNIEXPORT void JNICALL Java_com_HelloWorld_modifyStaticHappyScore
  (JNIEnv *env, jobject obj){
    jclass tClas = env->GetObjectClass(obj);

    jfieldID happyFiled = env->GetStaticFieldID(tClas, "happyScore", "D");
    if(nullptr == happyFiled) 
      return;
    jdouble JNIScore = env->GetStaticDoubleField(tClas, happyFiled);
    std::cout << "Native layer got the happy Score: " << JNIScore << std::endl;

    JNIScore *= 2;
    env->SetStaticDoubleField(tClas, happyFiled, JNIScore);
  }


  JNIEXPORT void JNICALL Java_com_HelloWorld_nativeCallBack
  (JNIEnv *env, jobject obj){
    jclass tclas = env->GetObjectClass(obj);
    jmethodID mID = env->GetMethodID(tclas, "callBack", "(Ljava/lang/String;)V");
    if(nullptr == mID)
      return;
    
    std::string message = "Thank you!";
    jstring JNImessage = env->NewStringUTF(message.c_str());
    env->CallVoidMethod(obj, mID, JNImessage);

  }

  JNIEXPORT jobject JNICALL Java_com_HelloWorld_getIntergerObject
  (JNIEnv *env, jobject obj, jint JNIInteger){
    //Step1: get a class instance of Interger
    jclass cls = env->FindClass("java/lang/Integer");

    jmethodID midInit = env->GetMethodID(cls, "<init>", "(I)V");
    if (nullptr == midInit)
    {
      return NULL;
    }
    jobject newObj = env->NewObject(cls, midInit, JNIInteger);

    return newObj;
  }

  JNIEXPORT jobjectArray JNICALL Java_com_HelloWorld_sumAndAverage
  (JNIEnv *env, jobject obj, jobjectArray inJNIArray){
    jclass cls = env->FindClass("java/lang/Integer");
    jmethodID midInteger = env->GetMethodID(cls, "intValue", "()I");
    if (nullptr == midInteger)
    {
      return NULL;
    }

    jsize length = env->GetArrayLength(inJNIArray);
    jint sum = 0;
    for (int i = 0; i < length; i++)
    {
      jobject objInteger = env->GetObjectArrayElement(inJNIArray, i);
      if(nullptr == objInteger) return NULL;
      jint value = env->CallIntMethod(objInteger, midInteger);
      sum += value;
    }
    
    double average = (double) sum / length;

    
    jclass classDouble = env->FindClass("java/lang/Double");
    //Allocate a objectArray 
    jobjectArray outJNIArray = env->NewObjectArray(2, classDouble, NULL);
    jmethodID midDoubleInit = env->GetMethodID(classDouble, "<init>", "(D)V");
    if (nullptr == midDoubleInit)
    {
      return NULL;
    }
    jobject objSum = env->NewObject(classDouble, midDoubleInit, (double)sum);
    jobject objAvg = env->NewObject(classDouble, midDoubleInit, (double)average);

    env->SetObjectArrayElement(outJNIArray, 0, objSum);
    env->SetObjectArrayElement(outJNIArray, 1, objAvg);
    return outJNIArray;
  }