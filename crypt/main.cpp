#include <iostream>
#include <string>
#include "crypt.h"

using namespace std;

int main(int argc, char* argv[])
{
    // ��Ҫ���ܵ�����
    /*string strPlain = "123qwe";
    char charPlain[] = "123qwe";*/
    // ���ܺ������
    string strEncoded;
    char* charEncoded = new char[100];
    // ���ܺ�����ݣ���strPlinһ��
    string strRecovered;
    char* charRecovered = new char[100];

    
    try
    {
        if (argc == 1) {
            throw exception();
        }
        string commandLine(argv[1]);
        if (commandLine == "-encrypt") {
            encrypt(argv[2], charEncoded);
            cout << charEncoded << endl;
            /*string str(argv[2]);
            encrypt(str, strEncoded);
            cout << strEncoded << endl;*/
        }
        else if (commandLine == "-decrypt") {
            decrypt(argv[2], charRecovered);
            cout << charRecovered << endl;
            /*string str(argv[2]);
            decrypt(str, strRecovered);
            cout << strRecovered << endl;*/
        }
        else {
            throw exception();
        }
    }
    catch (const std::exception&)
    {
        cout << "crypt.exe [command] [value]\ncommand:\n\t-encrypt\n\t-decrypt" << endl;
    }
   
    return 0;

}