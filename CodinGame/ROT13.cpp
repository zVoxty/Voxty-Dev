#include <iostream>
#include <string>

using namespace std;

int main()
{
    string yourString;
    getline(cin, yourString);
    int asciiA = 65;
    int asciiZ = 90;
    int ROT13 = 13;
    int asciiValue;
    for(int i = 0; i <= yourString.length(); i++){
        if(yourString[i] == ' '){
            cout << " ";
        }
        else{
            asciiValue = (int) yourString[i];
            if(asciiValue + ROT13 >= asciiZ){
                int temp = asciiZ - asciiValue + 1;
                ROT13 -= temp;
                int fin = asciiA + ROT13;
                cout << (char) fin;
            }
            else{
                asciiValue +=13;
                cout << (char) asciiValue;
            }
            ROT13 = 13;
        }
    }
    return 0;
}
