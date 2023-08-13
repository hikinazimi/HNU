#include<bits/stdc++.h>
using namespace std;
int dp[5010];
int main()
{
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	dp[0] = a;
	for (int i = 1; i < n; i++)
	{
		int flag = 0;
		int j;
		for (j = 1; j <= i; j++)
		{
			string c = s.substr(0, j);
			string d = s.substr(j, i - j + 1);
			if (c.find(d) != c.npos)//dÊÇcµÄ×Ó´®
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			dp[i] = min(dp[j - 1] + b, dp[i - 1] + a);
		else
			dp[i] = dp[i - 1] + a;
	}
	cout << dp[n - 1];
}
