#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int n;
	while(cin>>n&&n!=0){
		double a[n],b[n];
		double ave=0;
		double cha=0;
		for(int i=0;i<n;++i){
		cin>>a[i];
		ave+=a[i];
		}
		ave/=n;
		for(int i=0;i<n;++i){
		b[i]=(a[i]-ave)*(a[i]-ave);
		cha+=b[i];
		}
		cha/=n;
		cout<<int(cha)<<endl;	
	}
} 

