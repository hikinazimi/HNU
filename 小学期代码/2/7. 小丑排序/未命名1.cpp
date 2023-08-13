#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int n;
	int i = 1;
	while(1)
	{
		cin >> n;
		if (n == 0)
			break;
		else
			cout << "set-" << i << endl;
		i++;
		vector<string>str;
		for (int j = 1; j <= n; j++)
		{
			string s;
			cin >> s;
			str.insert(str.begin()+j/2,s);
		}
		for (int i = 0; i < str.size(); i++)
			cout << str[i] << endl;
		str.clear();
	}
}

