#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
void fun(string s)
{
	s += " ";
	stack<string>sta;
	size_t pos = s.find(" ");
	while (pos != s.npos)
	{
		string temp = s.substr(0, pos);
		sta.push(temp);
		sta.push(" ");
		s = s.substr(pos + 1, s.size());
		pos = s.find(" ");
	}
	sta.pop();
	while (!sta.empty())
	{
		cout << sta.top();
		sta.pop();
	}
	cout<<endl;
}
int main()
{
	string s;
	while (getline(cin, s))
	{
		fun(s);
	}
}
