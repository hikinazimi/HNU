#include<bits/stdc++.h>
using namespace std;
int fun(string a, string b)//判断a是否为b的子串
{
	int len = b.length() - a.length();
	if (len <= 0)
		return 0;
	else
	{
		string t = b.substr(len, b.length());
		if (a == t)
			return 1;
		else
			return 0;
	}
}
struct people
{
	string name;
	vector<string>number;
};
bool com(string a, string b)
{
	if (a.length() != b.length())
		return a.length() < b.length();
	else
		return a < b;
}
int main()
{
	int n;
	cin >> n;
	people pp[100];
	map<string, set<string> >m;
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			string temps;
			cin >> temps;
			m[name].insert(temps);
		}
	}

	int l = m.size();
	vector<string>vname[5];
	vector<string>v;
	int t = 0;
	for (map<string, set<string> >::iterator it = m.begin(); it != m.end(); it++)
	{
		pp[t].name = it->first;
		for (set<string>::iterator si = it->second.begin(); si != it->second.end(); si++)
		{
			int flag = 1;
			for (set<string>::iterator sk = it->second.begin(); sk != it->second.end(); sk++)
			{
				if (fun(*si, *sk))
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				pp[t].number.push_back(*si);
		}
		t++;
	}
	cout << t << endl;
	for (int i = 0; i < t; i++)
	{
		sort(pp[i].number.begin(), pp[i].number.end(), com);
		cout << pp[i].name << " " << pp[i].number.size() << " ";
		for (int j = 0; j < pp[i].number.size(); j++)
		{
			cout << pp[i].number[j] << " ";
		}
		cout << endl;
	}
}
