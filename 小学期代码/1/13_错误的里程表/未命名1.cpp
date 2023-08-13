#include<bits/stdc++.h>
using namespace std;
long long int fun(string s)
{
	int len = s.length();
	for (int j = 0; j < len; j++)
		{
			if (s[j] == '4')
				s[j] = '3';
			else if (s[j] == '5')
				s[j] = '4';
			else if (s[j] == '6')
				s[j] = '5';
			else if (s[j] == '7')
				s[j] = '6';
			else if (s[j] == '9')
				s[j] = '7';
		}
		long long int num=stoll(s,nullptr,8);
		return num;
}


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		cout<<fun(s)<<endl;
	}
}

