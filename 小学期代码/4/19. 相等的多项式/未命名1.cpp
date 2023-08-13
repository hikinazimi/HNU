#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		int a[n],b[n+1],c[n+1];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=n-1;i>=0;i--)
			cin>>b[i];
		b[n]=1;
		c[0]=a[0];
		c[1]=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=i;j>=0;j--)
			{
				if(j==i)c[j]=1;
				else if(j==0)c[j]*=a[i-1];
				else c[j]=c[j]*a[i-1]+c[j-1];
			}
		}
		int flag=0;
		for(int i=0;i<=n;i++)
		{
			if(b[i]!=c[i])
			{
				cout<<"N"<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0)
			cout<<"Y"<<endl;
		
	}
}
