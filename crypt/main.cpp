#include <iostream>
#include <string>
#include "crypt.h"
#include "httplib.h"
#include <Windows.h>

using namespace std;

int main(int argc, char* argv[])
{
    httplib::Server svr;

    svr.Get("/", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("Hello World!", "text/plain");
    });

    svr.Post("/decrypt", [&](const httplib::Request& req, httplib::Response& res) {
        auto size = req.files.size();
        const auto& file = req.get_file_value("password");
        string strEncoded = file.content;
        string charRecovered;
        decrypt(strEncoded, charRecovered);
        res.set_content(charRecovered, "text/plain");
    });

    svr.Post("/encrypt", [&](const httplib::Request& req, httplib::Response& res) {
        auto size = req.files.size();
        const auto& file = req.get_file_value("password");
        string strPlain = file.content;
        string strEncoded;
        encrypt(strPlain, strEncoded);
        res.set_content(strEncoded, "text/plain");
    });

    svr.listen("0.0.0.0", 30006);
}

//int main(int argc, char* argv[])
//{
//    // 需要加密的数据
//    /*string strPlain = "123qwe";
//    char charPlain[] = "123qwe";*/
//    // 加密后的数据
//    string strEncoded;
//    char* charEncoded = new char[100];
//    // 解密后的数据，和strPlin一样
//    string strRecovered;
//    char* charRecovered = new char[100];
//
//    
//    try
//    {
//        if (argc == 1) {
//            throw exception();
//        }
//        string commandLine(argv[1]);
//        if (commandLine == "-encrypt") {
//            encrypt(argv[2], charEncoded);
//            cout << charEncoded << endl;
//            /*string str(argv[2]);
//            encrypt(str, strEncoded);
//            cout << strEncoded << endl;*/
//        }
//        else if (commandLine == "-decrypt") {
//            decrypt(argv[2], charRecovered);
//            cout << charRecovered << endl;
//            /*string str(argv[2]);
//            decrypt(str, strRecovered);
//            cout << strRecovered << endl;*/
//        }
//        else {
//            throw exception();
//        }
//    }
//    catch (const std::exception&)
//    {
//        cout << "crypt.exe [command] [value]\ncommand:\n\t-encrypt\n\t-decrypt" << endl;
//    }
//   
//    return 0;
//
//}