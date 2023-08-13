#include<bits/stdc++.h>
using namespace std;
int n;
int fun(int x)
{
	while (x)
	{
		if (x % 10 == 7)
			return 1;
		x /= 10;
	}
	return 0;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (i % 7 == 0)
			cout << i << endl;
		else if (fun(i))
			cout << i << endl;
		else
			continue;
	}
	return 0;
}
