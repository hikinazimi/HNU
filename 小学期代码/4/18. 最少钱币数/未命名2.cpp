#include<bits/stdc++.h>
using namespace std;
int dp[2010];//代表钱币的数量
int w[20];//钱币的面额
void fun(int sum,int n)
{
	for (int j = 1; j <= sum; j++)
		dp[j] = 10000;
	dp[0]=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (j >= w[i])
			{
				dp[j] = min(dp[j], dp[j - w[i]] + 1);
			}
			else
				continue;
		}
	}
}
int main()
{
	int sum;
	while (cin >> sum, sum)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> w[i];
		}
		sort(w, w+n);
		fun(sum, n);
		if (dp[sum] == 10000)
			cout << "Impossible" << endl;
		else
			cout << dp[sum] << endl;
	}
}
