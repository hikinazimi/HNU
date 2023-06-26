#include<bits/stdc++.h>
using namespace std;
void fun(int i, int n)
{
	string a = to_string(i);
	string b = to_string(n);
	if (a.find(b) != a.npos)
		cout << i << " ";
}
int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		if (i % n == 0)
			cout << i << " ";
		else
			fun(i, n);
	}
}

