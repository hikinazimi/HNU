#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		int cnt[10] = { 0 };
		int temp[n];
		for (int i = 0; i < n; i++)
		{
			cin >> temp[i];
			cnt[temp[i] ]++;
		}
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cnt[temp[i]]--;
			for (int j = 0; j < temp[i]; j++)
			{
				sum += cnt[j];
			}
		}
		cout << sum << endl;
	}
}
