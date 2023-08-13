#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = 10000000;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		a[u][v] = c;
		a[v][u] = c;
	}
	for (int k = 0; k < n; k++)
	{
		for(int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] > a[i][k] + a[k][j])
					a[i][j] = a[i][k] + a[k][j];
			}
		}
	}
	int max = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[0][i] > max&&a[0][i]!= 10000000)
			max = a[0][i];
	}
	cout << max;
}

