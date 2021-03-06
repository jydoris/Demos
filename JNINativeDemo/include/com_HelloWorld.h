/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_HelloWorld */

#ifndef _Included_com_HelloWorld
#define _Included_com_HelloWorld
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_HelloWorld
 * Method:    hello
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_HelloWorld_hello
  (JNIEnv *, jobject);

/*
 * Class:     com_HelloWorld
 * Method:    setRecordValue
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_HelloWorld_setRecordValue
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_HelloWorld
 * Method:    getRecordValue
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_HelloWorld_getRecordValue
  (JNIEnv *, jobject);

/*
 * Class:     com_HelloWorld
 * Method:    queryJobViaName
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_HelloWorld_queryJobViaName
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_HelloWorld
 * Method:    setAges
 * Signature: ([I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_HelloWorld_setAges
  (JNIEnv *, jobject, jintArray);

/*
 * Class:     com_HelloWorld
 * Method:    modifyDataViaName
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_HelloWorld_modifyDataViaName
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_HelloWorld
 * Method:    modifyStaticHappyScore
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_HelloWorld_modifyStaticHappyScore
  (JNIEnv *, jobject);

/*
 * Class:     com_HelloWorld
 * Method:    nativeCallBack
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_HelloWorld_nativeCallBack
  (JNIEnv *, jobject);

/*
 * Class:     com_HelloWorld
 * Method:    getIntergerObject
 * Signature: (I)Ljava/lang/Integer;
 */
JNIEXPORT jobject JNICALL Java_com_HelloWorld_getIntergerObject
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_HelloWorld
 * Method:    getAnotherInteger
 * Signature: (I)Ljava/lang/Integer;
 */
JNIEXPORT jobject JNICALL Java_com_HelloWorld_getAnotherInteger
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_HelloWorld
 * Method:    sumAndAverage
 * Signature: ([Ljava/lang/Integer;)[Ljava/lang/Double;
 */
JNIEXPORT jobjectArray JNICALL Java_com_HelloWorld_sumAndAverage
  (JNIEnv *, jobject, jobjectArray);

#ifdef __cplusplus
}
#endif
#endif
