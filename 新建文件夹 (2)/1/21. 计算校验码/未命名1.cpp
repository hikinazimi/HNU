#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int trans(char a)
{
	int temp = 0;
	if ('0' <= a && a <= '9')
		temp =a- '0';
	else
		temp =a- 'a'+10;
	return temp;
}
int muliti(string s)
{
	int len = s.length();
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += trans(s[i]);
	}
	return sum;

}
void fun(int B, string num)
{
	int temp = muliti(num);
	int i = 0;
	for (; i < B - 1; i++)
	{
		if ((i + temp) % (B - 1) == 0)
			break;
	}
	if (0 <= i && i < 10)
		cout << i << endl;
	else
	{
		char s = i-10 + 'a';
		cout << s<< endl;
	}


}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int B;
		string num;
		cin >> B >> num;
		fun(B, num);
	}
}
