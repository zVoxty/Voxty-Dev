#include<iostream>

using namespace std;

int n,i,a[95];

main(){
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]>15){ break;}}
	cout<<min(a[i-1]+15,90);
}