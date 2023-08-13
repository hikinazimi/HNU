#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn = 200001;
int give[maxn];
int done[maxn];//判断节点是否
vector<int>fi;
struct edge
{
	int from, to;
	edge(int u, int v) :from(u), to(v) {}
};
vector<int>edges[maxn];//头节点
vector<edge>s;//边的编号
bool com(int l, int r)
{
	int ln = 0, rn = 0;
	for (int i = 0; i < n; i++) {
		if (give[i] == l) ln = i;
		if (give[i] == r) rn = i;
	}
	return ln < rn;
}
vector<int> findchild(vector<int>child)
{
	vector<int>v;
	for (vector<int>::iterator it = child.begin(); it != child.end(); it++)
	{
		for (int i = 0; i < edges[*it].size(); i++)
		{
			if (!done[s[edges[*it][i]].to])
			{
				v.push_back(s[edges[*it][i]].to);
				done[s[edges[*it][i]].to] = 1;
			}
		}

	}
	sort(v.begin(), v.end(),com);
	for (int i = 0; i < v.size(); i++)
		fi.push_back(v[i]);
	return v;
}
void bfs(int n)
{
	memset(done, 0, sizeof(done));
	vector<int>child;
	child.push_back(1);
	done[1] = 1;
	fi.push_back(1);
	while (!child.empty())
	{
		child = findchild(child);
	}
}
bool com(edge A, edge B)
{
	if (A.from == B.from)
		return A.to < B.to;
	else
		return A.from < B.from;
}
int main()
{
	cin >> n;
	cout << n << endl;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << a << " " << b << endl;
		s.push_back(edge(a, b));
		s.push_back(edge(b, a));
	}
	int t, ret = 0;
	for (int i = 0; i < n; i++)
		cin >> give[i];
	for (int i = 0; i < s.size(); i++)
		edges[s[i].from].push_back(i);
	bfs(n);
	for (int i = 0; i < n; i++)
	{
		if (fi[i] != give[i])
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";

}
