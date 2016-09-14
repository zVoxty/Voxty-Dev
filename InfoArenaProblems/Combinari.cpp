#include <iostream>
#include <fstream>
using namespace std;
ifstream f("combinari.in");
ofstream g("combinari.out");
int den, ltk, v[20];
void afisare()
{
    for(int i=1; i<=ltk; i++)
        g << v[i] << " ";
    g << "\n";
}
void backtrack(int x)
{
    for(int i=v[x-1]+1; i<=den; i++)
    {
        v[x]=i;
        if(x==ltk) afisare();
        else backtrack(x+1);
    }
}
int main()
{
    f >> den >> ltk;
    backtrack(1);
    f.close();
    g.close();
    return 0;
}