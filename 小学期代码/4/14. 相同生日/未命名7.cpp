#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<pair<int,int>, vector<string>>m;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		int mon, day;
		cin >> s >> mon >> day;
		vector<string >v;
		v.push_back(s);
		if (m.count({ mon,day }) == 0)
			m.insert({ {mon,day} ,v });
		else
			m[{mon, day}].push_back(s);
	}
	map<pair<int, int>, vector<string>>::iterator it;
	vector<string > ::iterator itv;
	for (it = m.begin(); it != m.end(); it++)
	{
		cout << it->first.first<<" " << it->first.second << " ";
		for (itv = it->second.begin(); itv != it->second.end(); itv++)
			cout << *itv << " ";
		cout << endl;
	}
}


