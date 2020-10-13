#include <iostream>
#include <string>
#include "config.h"
#include "crypt/crypt.h"
#include "aes.h"

using namespace CryptoPP;
using namespace std;

int main(int argc, char* argv[])
{
    // 加密用的key
    byte key[AES::MAX_KEYLENGTH] = "12345678abcdefgh";
    // 需要加密的数据
    string strPlain = "123qwe";
    // 加密后的数据
    string strEncoded;
    // 解密后的数据，和strPlin一样
    string strRecovered;
    cout << sizeof(key) / sizeof(byte) << endl;
    int length = sizeof(key);
    cout << "key is: " << key << endl;
    cout << "plain is: " << strPlain << endl;
    Crypt test;
    test.encrypt(key, length, strPlain, strEncoded);
    cout << "*********** " << "Encoded: " << strEncoded << " ***********" << endl;
    test.decrypt(key, length, strRecovered, strEncoded);
    cout << "*********** " << "Decoded: " << strRecovered << " ***********" << endl;
    return 0;
}