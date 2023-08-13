#include<bits/stdc++.h>
using namespace std;
int main()
{
	string N;
	cin >> N;
	map<int, int>m;
	for (int i = 0; i < N.length(); i++)
	{
		int n = N[i] - '0';
		m[n]++;
	}
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << ":" << it->second << endl;
	}
}
