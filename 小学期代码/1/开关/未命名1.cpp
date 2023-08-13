#include<iostream>
using namespace std;
int anl(int *a,int m)
{
	int ret=1;
	for(int i=0;i<m;i++)
		if(a[i]==0) ret=0;
	return ret;
}
int main()
{
	int n,m;
	cin>>n>>m;
	string a[n];
	int lamp[m];
	for(int j=0;j<m;j++)
		lamp[j]=0;
		

	for(int i=0;i<n;i++)//ÊäÈë 
	{
		cin>>a[i];
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='1')
				lamp[j]++;
		}
	}
	int ret=0;
	int b[m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			b[j]=lamp[j];
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='1')
				b[j]--;
		}
		if(anl(b,m)==1)
			ret=1;	
	}
	if(ret==1)
	cout<<"YES";
	else
	cout<<"NO";
	
}

