#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct ss
{
	int n;//ÎÞÐò¶È
	string str;
};
int com(ss a, ss b)
{
	return a.n < b.n;
}
void fun(struct ss &q,int m)
{
	int sum = 0;
	for (int i = 0; i < m-1; i++)
	{
		for (int j = i; j < m; j++)
		{
			if (q.str[i] > q.str[j])
				sum++;
		}
	}
	q.n = sum;
}
int main()
{
	int n, m;
	cin >> n >> m;
	ss q[m];
	for (int i = 0; i < m; i++)
	{
		cin >> q[i].str;
		fun(q[i], n);
	}
	sort(q, q + m, com);
	for (int i = 0; i < m; i++)
	{
		cout << q[i].str << endl;
	}
}

