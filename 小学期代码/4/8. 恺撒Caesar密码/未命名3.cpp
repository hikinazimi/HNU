#include<bits/stdc++.h>
using namespace std;
string fun(string s)
{
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (s[i] <= 'Z' && s[i] >= 'A')
		{
			s[i] -= 5;
			if (s[i] < 'A')
				s[i] += 26;
		}
		else
			continue;
	}
	return s;
}
int main()
{
	string a, b, c;
	while (1)
	{
		cin >> a;
		cin.ignore();
		if (a == "ENDOFINPUT")
			break;
		getline(cin, b);
		cout << fun(b) << endl;
		cin >> c;
	}
}
