#include<iostream>
using namespace std;
long long int fun(string t)
{
	long long int temp=1;
	long long sum = 0;
	int len = t.length();
	for (int i = len - 1; i >= 0; i--)
	{
		sum += (t[i] - 'a') * temp;
		temp *= 26;
	}
	return sum;


}
void solution(long long int a,long long int b)
{
	long long t = a + b;
	char s[20] = {};
	int i = 0;                                                                                                                                               
	while (t != 0)
	{
		 s[i++]= (t % 26 + 'a');
		 t /= 26;
	}
	i--;
	for (; i >= 0; i--)
		cout << s[i];
	cout << endl;
}
int main()
{
	int n;
	cin >> n;
	string a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		solution(fun(a), fun(b));
	}
}
