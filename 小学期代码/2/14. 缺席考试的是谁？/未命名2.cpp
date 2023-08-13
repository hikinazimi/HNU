#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		map<string, int>name;
		for (int i = 0; i < n * 2 - 1; i++)
		{
			string s;
			cin >> s;
			name[s]++;
		}
		for (map<string, int>::iterator it = name.begin(); it != name.end(); it++)
		{
			if (it->second %2 == 1)
			{
				cout << it->first << endl;
				break;
			}
		}
	}
}
