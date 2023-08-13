#include<bits/stdc++.h>
using namespace std;
struct people
{
	int pre;
	int end;
	int flag;
};
int seat[10001];
int pd(int sum,int n)
{
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (seat[i] == 0) ret++;
		if (ret == sum)return i;
		if (seat[i] != 0)ret = 0;
	}
	return -1;
}
void in(int a,int b, map<int, people>&tmp,int n)
{
	if (tmp[a].flag == 1)
	{
		cout << "no" << endl;
		return;
	}
	int end=pd(b, n);
	if (end == -1)
	{
		cout << "no" << endl;
		return;
	}
	else
	{
		tmp[a].flag = 1;
		tmp[a].end = end;
		tmp[a].pre = end - b+1;
		cout << "yes" << endl;
		for (int i = tmp[a].pre; i <= tmp[a].end; i++)
			seat[i] = 1;
	}
}
void out(int a, map<int, people>& tmp)
{
	if (tmp[a].flag == 0)
	{
		cout << "no" << endl;
		return;
	}
	else
	{
		cout << "yes" << endl;
		for (int i = tmp[a].pre; i <= tmp[a].end; i++)
			seat[i] = 0;
		tmp[a].flag = 0;
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	int sum = n * n;
	int k;
	cin >> k;
	map<int, people>tmp;
	tmp[30];
	for (int i = 0; i < k; i++)
	{
		string button;
		int a, b;
		cin >> button;
		if (button == "in")
		{
			cin >> a >> b;
			in(a, b, tmp,sum);
		}
		else
		{
			cin >> a;
			out(a,tmp);
		}
		
	}
}
