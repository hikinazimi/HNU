#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int cnt = 1, sum = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[i - 1])
			cnt++;
		else
		{
			sum=max(cnt, sum);
			cnt = 1;
		}
	}
	cout << max(cnt, sum);
}
