#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
			break;
		int temp[n];
		for(int i=0;i<n;i++)
			cin>>temp[i];
		int sum=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
				{
					if(temp[i]>temp[j])
						sum++;
				}
		}
		cout<<sum<<endl;
	}
}

