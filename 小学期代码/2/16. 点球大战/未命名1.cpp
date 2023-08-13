#include<bits/stdc++.h>
using namespace std;
void com(int i)
{
	if (i == 1)
		cout << "O ";
	else
		cout << "X ";
}
void com(vector<int >a,vector<int>b)
{
	int sum = 0;

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] > 0)
			sum++;
	}
	int temp = a.size() + b.size();
	if (temp % 2 == 1&&a.size()<b.size())
		cout << "- " << sum << endl;
	else
		cout << sum << endl;
}
void fun(int n, vector<int>a, vector<int> b)
{
	for (int i = 1; i <= (n+1) / 2 ; i++)
		cout << i << " ";
	cout << "Score" << endl;
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		com(a[i]);
	}
	com(a, b);
	for (int i = 0; i < n / 2; i++)
	{
		com(b[i]);
	}
	 com(b, a);
}
int main()
{
	int n;
	while (1)
	{
		cin >> n;
		vector<int>a;
		vector<int>b;
		cin.ignore();
		if (n == 0)
			break;
		string  ss;
		for (int i = 0; i < n; i++)
		{
			getline(cin, ss);
			int pos = ss.find("no good");
			if (i % 2 == 0)
			{
				if (pos == -1)
					a.push_back(1);
				else
					a.push_back(0);
			}
			else
			{
				if (pos == -1)
					b.push_back(1);
				else
					b.push_back(0);
			}
		}
		fun(n,a, b);
	}
}
