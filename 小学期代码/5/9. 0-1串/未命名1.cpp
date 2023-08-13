#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int sum = 0;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			for (int k = 0; k <n; k++)
			{
				if (k<i || k>j)
					sum += a[k];
				else
					sum += 1 - a[k];
			}
			if (sum > max)
				max = sum;
			sum = 0;
		}
	}
	cout << max;
}
