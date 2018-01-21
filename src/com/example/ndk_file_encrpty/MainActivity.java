package com.example.ndk_file_encrpty;


import java.io.File;

import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}
	
	public void encrypt(View view){
		String path = Environment.getExternalStorageDirectory().getAbsolutePath()+File.separator+"man.jpg";
		String new_path = Environment.getExternalStorageDirectory().getAbsolutePath()+File.separator+"man_encrypt.jpg";
		Cryptor.encrypt(path, new_path);
	}
	
	public void decrypt(View view){
		String path = Environment.getExternalStorageDirectory().getAbsolutePath()+File.separator+"man_encrypt.jpg";
		String new_path = Environment.getExternalStorageDirectory().getAbsolutePath()+File.separator+"man_decrypt.jpg";
		Cryptor.decrypt(path, new_path);
	}

}
