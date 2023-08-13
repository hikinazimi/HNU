#include<bits/stdc++.h>
using namespace std;
stack<string>ford, bk;
void back(string &now)
{
	if (bk.empty())
	{
		cout << "Ignored" << endl;
		return;
	}
	ford.push(now);
	now = bk.top();
	bk.pop();
	cout << now << endl;
}
void forward(string& now)
{
	if (ford.empty())
	{
		cout << "Ignored" << endl;
		return;
	}
	bk.push(now);
	now = ford.top();
	ford.pop();
	cout << now << endl;
}
void visit(string s,string &now)
{
	bk.push(now);
	now = s;
	cout << now << endl;
	while (ford.empty() != 1)
		ford.pop();
}

int main()
{
	string now = "http://www.game.org/";
	string s;
	while (cin>>s,s!="QUIT")
	{
		if (s == "VISIT")
		{
			string url;
			cin >> url;
			visit(url, now);
		}
		else if (s == "BACK")
			back(now);
		else
			forward(now);
	}
}
