#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a, b;
	map<char, int>m1, m2;
	cin >> a >> b;
	int len1 = a.length();
	int len2 = b.length();
	for (int i = 0; i < len1; i++)
	{
		m1[a[i]]++;
	}
	for (int i = 0; i < len2; i++)
	{
		m2[b[i]]++;
	}
	int cha = 0;
	for (map<char, int>::iterator it = m2.begin(); it != m2.end(); it++)
	{
		if (m1[it->first] < it->second)//Èç¹û²»¹»
			cha += it->second - m1[it->first];
	}
	if (cha > 0)
	{
		cout << "No " << cha;
	}
	else
		cout << "Yes " << len1 - len2;
}
