#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//You must convert given binary into hexadecimal.

int main()
{
    const string hexaString = "0123456789abcdef";
    string yourString;
    getline(cin, yourString);

    int convertFromBinar = 8*(yourString[2] - '0') + 4*(yourString[3] - '0') + 2*(yourString[4] - '0') + (yourString[5] - '0');
    char answer = hexaString[convertFromBinar];
    cout << "0x" << answer;

    return 0;
}


