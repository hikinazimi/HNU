#include<bits/stdc++.h>
using namespace std;
int sum[110];
int dp[110][3];
int dfs(int i, int pre)
{
	int cnt = 0;
	if (i < 0)return 0;
	if (dp[i][pre] != 0)return dp[i][pre];
	if (sum[i] == 3)
	{
		if (pre == 1)
			 cnt += max(dfs(i - 1, 2) + 1, dfs(i - 1, 0));
		else if (pre == 2)
			 cnt += max(dfs(i - 1, 1) + 1, dfs(i - 1, 0));
		else
			 cnt += max(max(dfs(i - 1, 1) + 1, dfs(i - 1, 2) + 1), dfs(i - 1, 0));
	}
	if (sum[i] == 0)
		 cnt += dfs(i - 1, 0);
	if (sum[i] == 1)
	{
		if (pre == 1)
			 cnt += dfs(i - 1, 0);
		else
		{
			 cnt += max(dfs(i - 1, 1) + 1, dfs(i - 1, 0));
		}
	}
	if (sum[i] == 2)
	{
		if (pre == 2)
			 cnt += dfs(i - 1, 0);
		else
		{
			cnt += max(dfs(i - 1, 2) + 1, dfs(i - 1, 0));
		}
	}
	if (cnt > dp[i][pre])
		dp[i][pre] = cnt;
	return cnt;
}
int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> sum[i];
	}
	cout << n - dfs(n , 0);
}
