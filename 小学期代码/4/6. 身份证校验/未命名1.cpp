#include<bits/stdc++.h>
using namespace std;
int w[17] = { 7, 9 ,10 ,5 ,8 ,4, 2 ,1, 6 ,3 ,7 ,9 ,10 ,5 ,8 ,4, 2 };
char y[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
void ans(string s)
{
	int sum = 0;
	for (int i = 0; i < 17; i++)
		sum = sum + (s[i] - '0') * w[i];
	if (y[sum % 11] == s[17])
		cout << 1<<endl; 
	else
		cout << 0<<endl;
}
int main()
{
	string number;
	while (cin >> number)
	{
		if (number[0] == '-')
			break;
		ans(number);
	}
}
