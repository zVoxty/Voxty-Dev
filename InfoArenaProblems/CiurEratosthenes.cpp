#include <stdio.h>
 
bool a[2000001];
 
int main()
{
    int x;
    freopen("ciur.in","r",stdin);
    freopen("ciur.out","w",stdout);
    scanf("%d",&x);
    int result=0;
    for(int i=2;i<=x;i++)
    {
        if(!a[i]){
            result++;
            for(int j=2;j*i<=x;j++){
                a[i*j]=1;
            }
        }
    }
    printf("%d",result);
}