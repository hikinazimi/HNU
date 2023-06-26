#include<iostream>
using namespace std;
int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if(n==0) break;
		int a,b,c;
		int sum=1,temp=0;
		cin>>a; b=a;
		for(int i=1;i<n;i++)
		{
			cin>>a;
			if(a==b)
			 sum++;
			else
			{
				if(temp<sum)  {temp=sum;c=b	;}	
				sum=1;
			}
			b=a;
		}	
		if(temp<sum)  {temp=sum;c=b	;}
		cout<<c<<endl;
	}
}

