#include<bits/stdc++.h>
using namespace std;
int com(string a)
{
	string b = a;
	reverse(a.begin(), a.end());
	if (a == b)
		return b.length();
	else
		return -1;
}
int main()
{
	int n;
	string s;
	while (cin >> n)
	{
		if (n == 0)
			break;
		cin >> s;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			string t;
			t = s.substr(i, s.size());
			if (com(t) != -1)
			{
				cout << n - com(t) << endl;
				break;
			}
		}
	}
}
