#include<bits/stdc++.h>
using namespace std;
const int maxn = 100001;
struct edge
{
	int from, to, dist;
	edge(int u,int v,int d):from(u),to(v),dist(d){}
}; 
vector<int>edges[maxn];//头节点
vector<edge>s;//边的编号
int path[maxn];
void findp(int x)
{
	if (path[x] == 1)
		cout << 1;
	else
		findp(path[x]);
	cout << " " << x;

}
void dfs(int n)
{
	int done[maxn];//判断节点是否
	int d[maxn];//权值;
	memset(done, 0, sizeof(done));
	for (int i = 0; i <= n; i++)
	{
		d[i] = 100000;
		path[i] = 1000000;
	}
	d[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		int x=0, m = 1000000;
		for (int j = 1; j <= n; j++)
		{
			if (!done[j] && m > d[j])
				m = d[x = j];
		}
		for (int j = 0; j < edges[x].size(); j++)
		{
			if (d[s[edges[x][j]].to] >= d[x] + s[edges[x][j]].dist)
			{
				d[s[edges[x][j]].to] = d[x] + s[edges[x][j]].dist;
				if (path[s[edges[x][j]].to] > x)
					path[s[edges[x][j]].to] = x;
			}
		}
		done[x] = 1;
	}
	if (d[n] == 100000)
	{
		cout << -1;
	}
	else
	{
		findp(n);
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		s.push_back(edge(a, b, c));
		s.push_back(edge(b, a, c));
		edges[a].push_back(2 * i );
		edges[b].push_back(2 * i + 1);
	}
	dfs(n);
}
