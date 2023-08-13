#include<bits/stdc++.h>
using namespace std;
int main()
{
	double m;
	int n;
	while (cin >> m >> n, n != 0)
	{
		int sum[30], ret = 0;
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < n; i++)//Ò»ÐÐ
		{
			int x, flag = 1;
			int total = 0;
			cin >> x;
			for (int j = 0; j < x; j++)
			{
				char Type, t;
				double price;
				cin >> Type >> t >> price;
				if ((Type == 'A' || Type == 'B' || Type == 'C') && price <= 600)
					total+=price*100;
				else
					flag = 0;
			}
			cout << endl;
			if (flag && total <= 100000)
				sum[ret++] = total ;

		}
		int dp[int(m * 100 )+ 1];
		memset(dp, 0, sizeof(dp));
		ret;
		for (int i = 0; i < ret; i++)
		{
			for (int j = m * 100; j >= sum[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - sum[i]] + sum[i]);
			}
		}
		double tt = dp[int(m * 100)] * 1.0 / 100;
		cout << fixed << setprecision(2) << tt << endl;
	}
}

