#include "crypt.h"
#include "hex.h"
#include "aes.h"
#include "modes.h"
#include <cstring>

using namespace CryptoPP;
using namespace std;

void encrypt(char* password, char* result) {
    byte key[AES::MAX_KEYLENGTH] = "12345678abcdefgh";
    string strEncoded;
    string strCipher;
    string strPlain;
    strPlain = password;
    try {
        // encrypt with ECB mode
        ECB_Mode< AES >::Encryption e;
        e.SetKey(key, sizeof(key));

        // 加密
        StringSource(strPlain, true,
            new StreamTransformationFilter(e,
                new StringSink(strCipher) // StringSink
            ) // StreamTransformationFilter
        ); // StringSource
    }
    catch (const Exception& e) {
        cerr << e.what() << endl;
        exit(1);
    }

    // print cipher string
    strEncoded.clear();
    // 加密的数据编码
    StringSource(strCipher, true,
        new HexEncoder(
            new StringSink(strEncoded) // StringSink
        ) // HexEncoder
    ); // StringSource
    // result = strEncoded.c_str(); 
    strcpy_s(result, strlen(strEncoded.c_str()) + 1, strEncoded.c_str());
}

void decrypt(char* encryptedPassword, char* result) {
    byte key[AES::MAX_KEYLENGTH] = "12345678abcdefgh";
    string strRecovered;
    string strCipher;
    string strEncoded;
    strEncoded = encryptedPassword;
    // 把要解密的字符串先解码
    StringSource(strEncoded, true,
        new HexDecoder(
            new StringSink(strCipher)
        )
    );
    try {
        // 解密
        ECB_Mode< AES >::Decryption d;
        d.SetKey(key, sizeof(key));

        // The StreamTransformationFilter removes padding as required.
        StringSource s(strCipher, true,
            new StreamTransformationFilter(d,
                new StringSink(strRecovered) // StringSink
            ) // StreamTransformationFilter
        ); // StringSource
        // result = strRecovered.c_str();
        strcpy_s(result, strlen(strRecovered.c_str()) + 1, strRecovered.c_str());
    }
    catch (const Exception& e) {
        cerr << e.what() << endl;
        exit(1);
    }
}

void encrypt(string& password, string& result) {
    byte key[AES::MAX_KEYLENGTH] = "12345678abcdefgh";
    string strEncoded;
    string strCipher;
    string strPlain;
    strPlain = password;
    try {
        // encrypt with ECB mode
        ECB_Mode< AES >::Encryption e;
        e.SetKey(key, sizeof(key));

        // 加密
        StringSource(strPlain, true,
            new StreamTransformationFilter(e,
                new StringSink(strCipher) // StringSink
            ) // StreamTransformationFilter
        ); // StringSource
    }
    catch (const Exception& e) {
        cerr << e.what() << endl;
        exit(1);
    }

    // print cipher string
    result.clear();
    // 加密的数据编码
    StringSource(strCipher, true,
        new HexEncoder(
            new StringSink(result) // StringSink
        ) // HexEncoder
    ); // StringSource
    // result = strEncoded.c_str(); 
    
}

void decrypt(string& encryptedPassword, string& result) {
    byte key[AES::MAX_KEYLENGTH] = "12345678abcdefgh";
    string strRecovered;
    string strCipher;
    string strEncoded;
    strEncoded = encryptedPassword;
    // 把要解密的字符串先解码
    StringSource(strEncoded, true,
        new HexDecoder(
            new StringSink(strCipher)
        )
    );
    try {
        // 解密
        ECB_Mode< AES >::Decryption d;
        d.SetKey(key, sizeof(key));

        // The StreamTransformationFilter removes padding as required.
        StringSource s(strCipher, true,
            new StreamTransformationFilter(d,
                new StringSink(result) // StringSink
            ) // StreamTransformationFilter
        ); // StringSource
        // result = strRecovered.c_str();
    }
    catch (const Exception& e) {
        cerr << e.what() << endl;
        exit(1);
    }
}

//Crypt::Crypt() {
//
//}
//
//Crypt::~Crypt() {
//
//}
//
//void Crypt::encrypt(const char* test, char* result) {
//    byte key[AES::MAX_KEYLENGTH] = "12345678abcdefgh";
//    string strEncoded;
//    string strCipher;
//    string strPlain;
//    strPlain = test;
//    try {
//        // encrypt with ECB mode
//        ECB_Mode< AES >::Encryption e;
//        e.SetKey(key, sizeof(key));
//
//        // 加密
//        StringSource(strPlain, true,
//            new StreamTransformationFilter(e,
//                new StringSink(strCipher) // StringSink
//            ) // StreamTransformationFilter
//        ); // StringSource
//    }
//    catch (const Exception& e) {
//        cerr << e.what() << endl;
//        exit(1);
//    }
//
//    // print cipher string
//    strEncoded.clear();
//    // 加密的数据编码
//    StringSource(strCipher, true,
//        new HexEncoder(
//            new StringSink(strEncoded) // StringSink
//        ) // HexEncoder
//    ); // StringSource
//    // result = strEncoded.c_str(); 
//    strcpy_s(result, strlen(strEncoded.c_str()) + 1, strEncoded.c_str());
//}
//
//void Crypt::decrypt(const char* test, char* result) {
//    byte key[AES::MAX_KEYLENGTH] = "12345678abcdefgh";
//    string strRecovered;
//    string strCipher;
//    string strEncoded;
//    strEncoded = test;
//    // 把要解密的字符串先解码
//    StringSource(strEncoded, true,
//        new HexDecoder(
//            new StringSink(strCipher)
//        )
//    );
//    try {
//        // 解密
//        ECB_Mode< AES >::Decryption d;
//        d.SetKey(key, sizeof(key));
//
//        // The StreamTransformationFilter removes padding as required.
//        StringSource s(strCipher, true,
//            new StreamTransformationFilter(d,
//                new StringSink(strRecovered) // StringSink
//            ) // StreamTransformationFilter
//        ); // StringSource
//        // result = strRecovered.c_str();
//        strcpy_s(result, strlen(strRecovered.c_str()) + 1, strRecovered.c_str());
//    }
//    catch (const Exception& e) {
//        cerr << e.what() << endl;
//        exit(1);
//    }
//}
//
//
//string Crypt::encrypt(string& strPlain) {
//    byte key[AES::MAX_KEYLENGTH] = "12345678abcdefgh";
//    string strEncoded;
//    string strCipher;
//    string strPlain;
//    try {
//        // encrypt with ECB mode
//        ECB_Mode< AES >::Encryption e;
//        e.SetKey(key, sizeof(key));
//
//        // 加密
//        StringSource(strPlain, true,
//            new StreamTransformationFilter(e,
//                new StringSink(strCipher) // StringSink
//            ) // StreamTransformationFilter
//        ); // StringSource
//    }
//    catch (const Exception& e) {
//        cerr << e.what() << endl;
//        exit(1);
//    }
//
//    // print cipher string
//    strEncoded.clear();
//    // 加密的数据编码
//    StringSource(strCipher, true,
//        new HexEncoder(
//            new StringSink(strEncoded) // StringSink
//        ) // HexEncoder
//    ); // StringSource
//    const char* result = strEncoded.c_str();
//    return strEncoded;
//}
//
//string Crypt::decrypt(string& strEncoded) {
//    byte key[AES::MAX_KEYLENGTH] = "12345678abcdefgh";
//    string strRecovered;
//    string strCipher;
//    string strEncoded;
//    // 把要解密的字符串先解码
//    StringSource(strEncoded, true,
//        new HexDecoder(
//            new StringSink(strCipher)
//        )
//    );
//    try {
//        // 解密
//        ECB_Mode< AES >::Decryption d;
//        d.SetKey(key, sizeof(key));
//
//        // The StreamTransformationFilter removes padding as required.
//        StringSource s(strCipher, true,
//            new StreamTransformationFilter(d,
//                new StringSink(strRecovered) // StringSink
//            ) // StreamTransformationFilter
//        ); // StringSource
//        const char* result = strRecovered.c_str();
//        return strRecovered;
//    }
//    catch (const Exception& e) {
//        cerr << e.what() << endl;
//        exit(1);
//    }
//}