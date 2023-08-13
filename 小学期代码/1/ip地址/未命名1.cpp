#include<iostream>
#include<string>
using namespace std;
int fun(string a)
{
	int s = stoi(a);
	int sum = 0, temp = s;
	while (temp) {
		int a = temp % 2;
		if (a == 1)
			sum++;
		temp = temp / 2;
	}
	return sum;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s, ss;
		cin >> s;
		ss = s;
		int sum = 0;
		int pos = ss.find('.');
		while (pos != ss.npos)
		{
			pos = ss.find('.');
			string a = ss.substr(0, pos);
			ss.erase(0, pos + 1);
			sum += fun(a);
		}
		cout << sum << endl;
	}
}
