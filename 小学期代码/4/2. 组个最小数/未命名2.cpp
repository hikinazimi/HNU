#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[10] = { 0 };
	int n;
	while (cin >> n)
	{
		a[n]++;
	}
	int i = 1;
	for (; i < 10; i++)
	{
		if (a[i] != 0)
			break;
	}
	cout << i;
	a[i]--;
	for (int i = 0; i < 10; i++)
	{
		while (a[i] != 0)
		{
			cout << i;
			a[i]--;
		}
	}
}
