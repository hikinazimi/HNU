#include<bits/stdc++.h>
using namespace std;
struct curse
{
	string cur;
	string func;
};
curse fun(string s)
{
	int pos = s.find("]");
	pos++;
	string a = s.substr(0, pos);
	string b = s.substr(pos + 1, s.length());
	int len = a.length()-2;
	a = a.substr(1, len);
	curse temp;
	temp.cur = a;
	temp.func = b;
	return temp;
}
int main()
{
	vector<curse>v;
	string ss;
	while (1)
	{
		getline(cin, ss);
		if (ss == "@END@")
			break;
		curse temp = fun(ss);
		v.push_back(temp);
	}
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin,s);
		int flag = 0;
		if (s[0] == '[')
		{
			s = s.substr(1, s.length()-2);
			flag = 1;
		}
		int ret = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (flag == 0)
			{
				if (v[i].func == s)
				{
					cout << v[i].cur << endl;
					ret = 1;
					break;
				}
			}
			else
			{
				if (v[i].cur == s)
				{
					cout << v[i].func << endl;
					ret = 1;
					break;
				}
			}
		}
		if (ret == 0)
			cout << "what?" << endl;
	}
}
