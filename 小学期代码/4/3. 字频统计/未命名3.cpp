#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		string s;
		cin >> s;
		int a = 0, b = 0;
		for (int i = 0; i < s.length()-1; i++)
		{
			if (s[i] == 'a' && s[i + 1] == 'b')
				a++;
			if (s[i] == 'b' && s[i + 1] == 'a')
				b++;
		}
		cout << a - b<<endl; 
	}

}
