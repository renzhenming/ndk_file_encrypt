package com.example.ndk_file_encrpty;

public class Cryptor {
	
	static{
		System.loadLibrary("ndk_file_encrpty");
	}
	
	public native static void encrypt(String normal_path,String crypt_path);
	
	public native static void decrypt(String crypt_path,String decrypt_path);

}
