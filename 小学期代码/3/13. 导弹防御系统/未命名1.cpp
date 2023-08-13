#include<bits/stdc++.h>
using namespace std;
int main()
{
	int sum[26];
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<26;i++)
		sum[i]=1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (a[j] <= a[i])
				sum[j] = max(sum[i]+1, sum[j]);
		}
	}
	int max1 = 0;
	for(int i=0;i<n;i++)
	{
		if (max1 < sum[i])
			max1 = sum[i];
	}
	cout << max1 ;
}
