#include <iostream>

#include <fcntl.h>
#include <string>
using namespace std;
int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wcout << L"Tiếng Việt có dấu" << std::endl;
    wstring test = L"unknown";
    std::wcout << L"Hãy nhập vào một chuỗi ký tự:" << std::endl;
    getline(std::wcin, test);
    std::wcout << L"Chuỗi ký tự mà bạn vừa mới nhập:" << std::endl;

    std::wcout << test; 
    return 0;
}
