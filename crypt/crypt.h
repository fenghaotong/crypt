#pragma once
//#include <string>
//
//using namespace std;
//
//class Crypt 
//{
//public:
//	Crypt();
//	~Crypt();
//	void encrypt(const char* test, char* result);
//	void decrypt(const char* test, char* result);
//	string encrypt(string& test);
//	string decrypt(string& test);
//};

//#ifndef DLLTESTDEF_H
//
//#define DLLTESTDEF_H

//extern "C"  __declspec(dllexport) const char* encrypt(const char* strPlain);
//extern "C"  __declspec(dllexport) const char* decrypt(const char* strEncoded);

//#endif
#include <iostream>

using namespace std;

void encrypt(char* password, char* result);
void decrypt(char* encryptedPassword, char* result);
extern "C"  __declspec(dllexport) void encrypt(string& password, string& result);
extern "C"  __declspec(dllexport) void decrypt(string& encryptedPassword, string& result);

// https://www.shuzhiduo.com/A/1O5EeMqa57/
// https://stackoverflow.com/questions/35673161/convert-go-byte-to-a-c-char