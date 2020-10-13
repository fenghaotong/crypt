#include <iostream>
#include <string>
#include "config.h"
#include "crypt/crypt.h"
#include "aes.h"

using namespace CryptoPP;
using namespace std;

int main(int argc, char* argv[])
{
    // �����õ�key
    byte key[AES::MAX_KEYLENGTH] = "12345678abcdefgh";
    // ��Ҫ���ܵ�����
    string strPlain = "123qwe";
    // ���ܺ������
    string strEncoded;
    // ���ܺ�����ݣ���strPlinһ��
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