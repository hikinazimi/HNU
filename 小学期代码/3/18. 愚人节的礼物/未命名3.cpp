#include<bits/stdc++.h>
using namespace std;
int main()
{
	string ss;
	while (cin >> ss)
	{
		int ret = 1;
		while (1)
		{
			if (ret == 0)
				break;
			ret = 0;
			for (int i = 0; i < ss.length() - 1; i++)
			{
				if (ss[i] == '(' && ss[i+1] == ')')
				{
					ss.erase(i, 2);
					ret = 1;
					i--;
				}
			}
		}
		for (int i = 0; i < ss.length(); i++)
		{
			if (ss[i] == 'B')
				cout << i << endl;
		}
	}
}
