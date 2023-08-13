#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
	int n;
	cin >> n;
	set<int>s;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s.insert(a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		int j = 1;
		for (set<int>::iterator it=s.begin();it!=s.end();it++,j++)
		{
			if (a[i] == *it)
			{
				cout << s.size() - j +1 << " ";
				break;
			}
		
		}
	}
}
