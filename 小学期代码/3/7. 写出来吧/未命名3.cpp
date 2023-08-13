#include<bits/stdc++.h>
using namespace std;
string func(char a)
{
	if (a == '0')
		return "ling";
	else if (a == '1')
		return "yi";
	else if (a == '2')
		return "er";
	else if (a == '3')
		return "san";
	else if (a == '4')
		return "si";
	else if (a == '5')
		return "wu";
	else if (a == '6')
		return "liu";
	else if (a == '7')
		return "qi";
	else if (a == '8')
		return "ba";
	else
		return "jiu";
}
int main()
{
	string ss;
	getline(cin, ss);
	int len = ss.length();
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		int temp = ss[i] - '0';
		sum += temp;
	}
	string s = to_string(sum);
	for (int i = 0; i < s.length()-1; i++)
		cout << func(s[i])<< " ";
	cout << func(s[s.length()-1]);


}
