#include<bits/stdc++.h>
using namespace std;
char trans(char s)
{
	if ('0' <= s && s <= '9')
		return s;
	else if (s == 'A' || s == 'B' || s == 'C')
		return '2';
	else if (s == 'D' || s == 'E' || s == 'F')
		return '3';
	else if (s == 'G' || s == 'H' || s == 'I')
		return '4';
	else if (s == 'J' || s == 'K' || s == 'L')
		return '5';
	else if (s == 'M' || s == 'N' || s == 'O')
		return '6';
	else if (s == 'P' || s == 'R' || s == 'S')
		return '7';
	else if (s == 'T' || s == 'U' || s == 'V')
		return '8';
	else if (s == 'W' || s == 'X' || s == 'Y')
		return '9';
	else
		return '+';
}
int main()
{
	int n;
	cin >> n;
	map<string, int>phoneNumber;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int len = s.length();
		int k = 0;
		string number;
		for (int j = 0; j < len; j++)
		{
			char temp=trans(s[j]);
			if (temp != '+')
			{
				if (k != 3)
				{
					number += temp;
					k++;
				}
				else
				{
					number += '-';
					number += temp;
					k++;
				}
			}
		}
		phoneNumber[number]++;
	}
	set<pair<string, int> >setr;
	for (map<string,int>::iterator it=phoneNumber.begin();it!=phoneNumber.end();it++)
	{
		if (it->second > 1)
		{
			pair<string, int>p;
			p.first = it->first;
			p.second = it->second;
			setr.insert(p);
		}
	}
	for (set<pair<string,int> >::iterator it=setr.begin();it!=setr.end();it++)
	{
		cout << it->first<<" "<<it->second << endl;
	}
	
}
