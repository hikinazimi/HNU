#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
class num
{
public:
	int n;
	int abs;
};
int fun(int a,int max,int min)
{
	int temp = abs(max + min - 2 * a);
	return temp;
}
bool com(num a,num b)
{
	if (a.abs != b.abs)
		return a.abs < b.abs;
	else
		return a.n < b.n;
}
int main()
{
	int n;
	cin >> n;
	vector<num>v(n);
	int max = -1, min = 1000000;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].n;
		if (max < v[i].n)max = v[i].n;
		if (min > v[i].n)min = v[i].n;
	}
	for (int i = 0; i < n; i++)
	{
		v[i].abs = fun(v[i].n, max, min);
	}
	sort(v.begin(), v.end(),com);
	cout << v[0].n;
}
