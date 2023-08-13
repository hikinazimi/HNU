#include<bits/stdc++.h>
using namespace std;
struct school
{
	int id;
	int score;
};
bool com(school a, school b)
{
	return a.score > b.score;
}
int main()
{
	int n;
	cin >> n;
	map<int, int>sch;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		sch[a] += b;
	}
	vector<school>v;
	for (map<int, int>::iterator it = sch.begin(); it != sch.end(); it++)
	{
		school a;
		a.id = it->first;
		a.score = it->second;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), com);
	cout << v[0].id << " " << v[0].score;
}
