#include <stdio.h>
#include <jni.h>

JNIEnv* create_vm(JavaVM **jvm)
{
    JNIEnv* env;
    JavaVMInitArgs args;
    JavaVMOption options;
    //JavaVMOption* options = new JavaVMOption[1];
    args.version = JNI_VERSION_1_6;
    args.nOptions = 1;
//    options.optionString = "-cp=.:./poc.jar";
    options.optionString = "-Djava.class.path=./automation-library.jar";
    args.options = &options;
    args.ignoreUnrecognized = 0;
    int rv;
    rv = JNI_CreateJavaVM(jvm, (void**)&env, &args);
    if (rv < 0 || !env)
        printf("Unable to Launch JVM %d\n",rv);
    else
        printf("Launched JVM! :)\n");
    return env;
}

void invoke_class(JNIEnv* env)
{
    jclass hello_world_class;
    jmethodID main_method;
    jmethodID square_method;
    jmethodID power_method;
    jmethodID get_clientID;
    jmethodID validate_Concurent_Plays;
    jint id=101;
    jint test;
    jstring clientID;
    jstring sessionID;
    jstring isCamValidation ;
    jint number=20;
    jint exponent=3;
    isCamValidation = "TRUE";
    hello_world_class = (*env)->FindClass(env, "helloWorld");
    main_method = (*env)->GetStaticMethodID(env, hello_world_class, "main", "([Ljava/lang/String;)V");
    square_method = (*env)->GetStaticMethodID(env, hello_world_class, "square", "(I)I");
    power_method = (*env)->GetStaticMethodID(env, hello_world_class, "power", "(II)I");
    get_clientID = (*env)->GetStaticMethodID(env, hello_world_class,"getID","(I)I");
    validate_Concurent_Plays = (*env)->GetStaticMethodID(env, hello_world_class, "Plays","(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I");
    (*env)->CallStaticVoidMethod(env, hello_world_class, main_method, NULL);
    printf("%d squared is %d\n", number,
        (*env)->CallStaticIntMethod(env, hello_world_class, square_method, number));
    printf("%d raised to the %d power is %d\n", number, exponent,	
        (*env)->CallStaticIntMethod(env, hello_world_class, power_method, number, exponent));
 printf("%d Client ID : %d\n",id,       
        (*env)->CallStaticIntMethod(env, hello_world_class, ID, id));
printf("%d Return ID : %d\n",id,
	(*env)->CallStaticIntMethod(env, hello_world_class, validate_Concurent_Plays,(*env)->NewStringUTF(env, "6059760"),(*env)->NewStringUTF(env, "1691359385")
,(*env)->NewStringUTF(env, isCamValidation))); 
}


int main(int argc, char **argv)
{
    JavaVM *jvm;
    JNIEnv *env;
    env = create_vm(&jvm);
    if(env == NULL)
        return 1;
   invoke_class(env);
//     invoke_sanity(env);
    return 0;
}
