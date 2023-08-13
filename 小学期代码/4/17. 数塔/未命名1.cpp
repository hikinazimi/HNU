#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int dp[10][10];
int dfs(int i,int j)
{
	if (a[i][j] == 0)return 0;
	if (dp[i][j] != 0)return dp[i][j];
	dp[i][j] = a[i][j] +max(dfs(i + 1, j + 1), dfs(i + 1, j));
	return dp [i][j];
}
void fun(int i,int j)
{
	if (dp[i][j] == 0)
		return;
	if (dp[i+1][j] > dp[i+1][j + 1])
	{
		cout << dp[i][j]-dp[i + 1][j] << " ";
		fun(i + 1, j);
	}
	else
	{
		cout << dp[i][j] - dp[i + 1][j+1] << " ";
		fun(i + 1, j+1);
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
        for (int j = 0; j <= i; j++)
            cin >> a[i][j];
	}
	dfs(0, 0);
	cout << dp[0][0] << endl;
	fun(0, 0);
}
