#include<bits/stdc++.h>
using namespace std;
void fun2(string s, int num[],int len)
{
	int a[10] = { 0 };
	int flag = 0;
	int t = s[0] - '0';
	for (int i = t + 1; i < 10; i++)
	{
		if (num[i] >= len)
		{
			a[i] = i;
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "NO" << endl;
	else
	{
		cout << "YES ";
		for (int i = 0; i < 10; i++)
			if (a[i] != 0)
			{
				int cnt = len-1;
				while (cnt)
				{
					a[i] = a[i] * 10 + i;
					cnt--;
				}
				cout << a[i] << " ";
			}
		cout << endl;
	}
}
void fun5(string s, int num[])
{
	int i = s[0] - '0'+1;
	int flag = 0;
	int a[10] = { 0 };
	for (; i <= 5; i++)
	{
		if (num[i] > 0 && num[i + 1] > 0 && num[i + 2] > 0 && num[i + 3] > 0 && num[i+4]  > 0)
		{
			flag = 1;
			a[i] = 1;
		}
	}
	if (flag == 0)
		cout << "NO" << endl;
	else
	{
		cout << "YES ";
		for (int i = 0; i < 10; i++)
			if (a[i] != 0)
			{
				cout << i * 10000 + (i + 1) * 1000 + (i + 2) * 100 + (i + 3) * 10 + (i + 4) << " ";
			}
		cout << endl;
	}

	

}

int main()
{
	string card;
	cin >> card;
	int num[10] = { 0 };
	for (int i = 0; i < card.length(); i++)
	{
		int temp = card[i] - '0';
		num[temp]++;
	}
	string s;
	while (cin >> s)
	{
		int len = s.length();
		if (len < 5)
		{
			fun2(s, num, len);
		}
		else
			fun5(s, num);
	}
}
