#include<bits/stdc++.h>
using namespace std;
struct people
{
	string name;
	string xuehao;
	int score;
};
bool com(people a, people b)
{
	return a.score > b.score;
}
int main()
{
	vector<people>v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		people peo;
		cin >> peo.name >> peo.xuehao >> peo.score;
		v.push_back(peo);
	}
	sort(v.begin(), v.end(), com);
	cout << v.begin()->name << " " << v.begin()->xuehao << endl;
	cout << (v.end()-1)->name << " " << (v.end()-1)->xuehao;
}
