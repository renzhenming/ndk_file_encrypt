#include <jni.h>
#include <com_example_ndk_file_encrpty_Cryptor.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


char password[] = "renzhenming";

//加密
JNIEXPORT void JNICALL Java_com_example_ndk_1file_1encrpty_Cryptor_encrypt(
		JNIEnv *env, jclass jcls, jstring normal_path_jstr,jstring crypt_path_jstr) {
	//jstring -> char*
	const char* normal_path = (*env)->GetStringUTFChars(env,normal_path_jstr,JNI_FALSE);
	const char* crypt_path = (*env)->GetStringUTFChars(env,crypt_path_jstr,JNI_FALSE);

	//打开文件
	FILE *normal_fp = fopen(normal_path, "rb");
	FILE *crypt_fp = fopen(crypt_path, "wb");
	//一次读取一个字符
	int ch;
	int i = 0; //循环使用密码中的字母进行异或运算
	int pwd_len = strlen(password); //密码的长度
	while ((ch = fgetc(normal_fp)) != EOF) { //End of File
		//写入（异或运算）
		fputc(ch ^ password[i % pwd_len], crypt_fp);
		i++;
	}
	//关闭
	fclose(crypt_fp);
	fclose(normal_fp);
}

//解密
JNIEXPORT void JNICALL Java_com_example_ndk_1file_1encrpty_Cryptor_decrypt(
		JNIEnv * env, jclass jcls, jstring crypt_path_jstr, jstring decrypt_path_jstr) {
	const char* crypt_path = (*env)->GetStringUTFChars(env,crypt_path_jstr,JNI_FALSE);
	const char* decrypt_path = (*env)->GetStringUTFChars(env,decrypt_path_jstr,JNI_FALSE);

	//打开文件
	FILE *normal_fp = fopen(crypt_path, "rb");
	FILE *crypt_fp = fopen(decrypt_path, "wb");
	//一次读取一个字符
	int ch;
	int i = 0; //循环使用密码中的字母进行异或运算
	int pwd_len = strlen(password); //密码的长度
	while ((ch = fgetc(normal_fp)) != EOF) { //End of File
		//写入（异或运算）
		fputc(ch ^ password[i % pwd_len], crypt_fp);
		i++;
	}
	//关闭
	fclose(crypt_fp);
	fclose(normal_fp);
}


//JNIEXPORT void JNICALL Java_com_example_ndk_file_encrpty_Cryptor_encrypt
//  (JNIEnv *env, jclass jcls, jstring normal,jstring crypt){
//	//jstring -> char *
//	const char *normal_char = (*env)->GetStringUTFChars(env,normal,JNI_FALSE);
//	const char *encypt_char = (*env)->GetStringUTFChars(env,crypt,JNI_FALSE);
//	//打开文件
//	FILE *normal_fp = fopen(normal_char,"rb");
//	FILE *crypt_fp = fopen(encypt_char,"wb");
//	//一次读取一个字符
//	int ch;
//	int i = 0;
//	int pwd_len = strlen(password);
//	while((ch = fgetc(normal_fp)) != EOF){
//		//写入
//		fputc(ch^password[i%pwd_len],crypt_fp);
//		i++;
//	}
//	//关闭
//	fclose(crypt_fp);
//	fclose(normal_fp);
//}



//JNIEXPORT void JNICALL Java_com_example_ndk_file_encrpty_Cryptor_decrypt
//(JNIEnv *env, jclass jcls, jstring crypt,jstring decrypt){
//	const char *crypt_char = (*env)->GetStringUTFChars(env,crypt,JNI_FALSE);
//	const char *decrypt_char = (*env)->GetStringUTFChars(env,decrypt,JNI_FALSE);
//	//打开文件
//	FILE *crypt_fp = fopen(crypt_char,"rb");
//	FILE *decrypt_fp = fopen(decrypt_char,"wb");
//
//	int ch;
//	int i = 0;
//	int pwd_len = strlen(password);
//	while((ch = fgetc(crypt_fp))!= EOF){
//		fputc(ch^password[i%pwd_len],decrypt_fp);
//		i++;
//	}
//	fclose(crypt_fp);
//	fclose(decrypt_fp);
//}
//
















