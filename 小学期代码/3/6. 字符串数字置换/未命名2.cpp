#include<bits/stdc++.h>
using namespace std;
string func(char a)
{
	if (a == '0')
		return "(Zero)";
	else if (a == '1')
		return "(One)";
	else if (a == '2')
		return "(Two)";
	else if (a == '3')
		return "(Three)";
	else if (a == '4')
		return "(Four)";
	else if (a == '5')
		return "(Five)";
	else if (a == '6')
		return "(Six)";
	else if (a == '7')
		return "(Seven)";
	else if (a == '8')
		return "(Eight)";
	else
		return "(Nine)";
}
int main()
{
	string ss;
	getline(cin, ss);
	int len = ss.length();
	int a[10]={0};
	for (int i = 0; i < len; i++)
	{
		int temp = ss[i] - '0';
		if (temp < 10 && temp >= 0)
		{
			a[temp]++;
			cout << func(ss[i]);
		}
		else
			cout << ss[i];
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";


}
