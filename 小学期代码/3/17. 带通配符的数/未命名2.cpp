#include<bits/stdc++.h>
using namespace std;
void fun(string a, string b, int c)
{
	int sum = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != '?')
		{
			if (a[i] > b[i]) 
			{ 
				sum += pow(10, c); 
				break; 
			}
			if (a[i] < b[i])break;
		}
		else
		{
			int temp = 9 - (b[i] - '0');
			c--;
			sum += temp * pow(10, c);
		}
	}
	cout << sum << endl;
}
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		int cnt = 0;
		for (int i = 0; i < a.length(); i++)
			if (a[i] == '?')
				cnt++;
		fun(a, b, cnt);
	}
}
