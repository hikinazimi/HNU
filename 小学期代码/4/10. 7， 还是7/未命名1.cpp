#include<bits/stdc++.h>
using namespace std;
void finds(int a)
{
	int temp=a;
	while(a)
	{
		if(a%10==7)
		{
			cout<<temp<<endl;
			break;
		}
		a/=10;
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i%7==0)
			cout<<i<<endl;
		else
			finds(i);
	}
}

