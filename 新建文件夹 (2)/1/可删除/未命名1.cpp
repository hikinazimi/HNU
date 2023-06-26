#include<iostream>
using namespace std;
int main()
{
	int n;
	int a,b;
	int l=0,r=0;
	cin>>n; 
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		if(a<0)	 l++;
		else	 r++;
	}
	if(l<=1||r<=1)
	cout<<"Yes";
	else cout<<"No";
}

