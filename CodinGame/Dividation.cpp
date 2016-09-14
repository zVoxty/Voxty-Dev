#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

// You are given a number n and a prime number p.
// You must tell the greatest power of p that divides n!

using namespace std;

bool prime(int x)
{
    for(int i=2; i<= sqrt(x); i++)
    {
        if ((x%i) != 0)
            return true;
        else
            return false;
    }
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    int p;
    cin >> p; cin.ignore();
    int nFact = 1;
    int answer = 1;
    int maxi = 1000;

    if(n < p){
        cout << "0";
    }
    else{
        for(int i = 1; i <= n; i++){
            nFact *= i;
        }
        int answer = sqrt(nFact);
        while(answer){
            int temp;
            temp = pow(p, answer);
            if(nFact % temp == 0){
                cout << answer;
                break;
            }
            answer--;
        }
    }

    return 0;
}
