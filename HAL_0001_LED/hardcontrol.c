//compile using 
//arm-linux-gcc -fPIC -shared hardcontrol.c -o libhardcontrol.so -I/usr/lib/jvm/java-1.7.0-openjdk-amd64/include/ -nostdlib /work/android-5.0.2/prebuilts/ndk/9/platforms/android-19/arch-arm/usr/lib/libc.so
//export LD_LIBRARY_PATH=.

#include <stdio.h>
#include <stdlib.h>
#include <jni.h> /*located in /usr/lib/jvm/java-1.7.0-openjdk-amd64/include*/
/*2. java <--> c mapping */
/* map java hello() <--> c c_hello()*/

/* This is called when a java program called */
/* System.loadLibrary("native"); */

#if 0
typedef struct 
{
    char *name;   /*method name used in .java file*/       
    char *signature;    /*use to describe return paramters and parameters*/
    void *fnPtr;  /*function pointer for our c function*/        
} JNINativeMethod;
#endif

//jint c_hello(JNIEnv *env, jobject cls, jint m)
//jstring JNICALL c_hello(JNIEnv *env, jobject cls, jstring str)
//jint c_hello(JNIEnv *env, jobject cls, jintArray arr)
jint ledOpen(JNIEnv *env, jobject cls)
{
	return 0;
}

void ledClose(JNIEnv *env, jobject cls)
{
}

jint ledCtrl(JNIEnv *env, jobject cls, jint which, jint status)
{
	return 0;
}

/*(paramters) return type*/
static const JNINativeMethod methods[] = {
	{"ledOpen", "()I", (void *)ledOpen},
	{"ledClose", "()V", (void *)ledClose},
	{"ledCtrl", "(II)I", (void *)ledCtrl},
};


JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *jvm, void *reserved)
{
	JNIEnv *env;
	jclass cls;
	//cached_jvm = jvm; /* cache the JavaVM pointer */
	
	if ((*jvm)->GetEnv(jvm, (void **)&env, JNI_VERSION_1_4)) {
		return JNI_ERR; /* JNI version not supported */
	}

	//reflect what is in .java class
	cls = (*env)->FindClass(env, "com/example/kelvin/hardlibrary/HardControl"); 
	if (cls == NULL) {
		return JNI_ERR;
	}
	
	/* map java hello() <--> c c_hello()*/
	if((*env)->RegisterNatives(env, cls, methods, sizeof(methods)/sizeof(methods[0])) < 0)
	{
		return JNI_ERR;
	}

	return JNI_VERSION_1_4;
}





