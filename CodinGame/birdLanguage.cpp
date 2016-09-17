#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string sentence;
    string vowels = "aeiouAEIOU";
    getline(cin, sentence);
    string answer;
    char place = 'n';

    for(int i = 0; i < sentence.length(); i++){
        cout << sentence[i];
        for(int j = 0; j <= vowels.length(); j++){
            if(sentence[i] == vowels[j]){
                cout << "p";
                place = 'y';
            }
        }
        if(place == 'y'){
            cout << sentence[i];
            place = 'n';
        }
    }
    return 0;
}
