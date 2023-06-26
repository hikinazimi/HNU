#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void fun(string s)
{
	string ret;
	s += " ";
	size_t pos = s.find(" ");
	while (pos != s.npos)
	{
		string temp = s.substr(0, pos);
		reverse(temp.begin(), temp.end());
		ret += temp;
		ret += " ";
		s = s.substr(pos + 1, s.size());
		pos = s.find(" ");
	}
	cout << ret<<endl;
}
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
		fun(s);
	}
}

