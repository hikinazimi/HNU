#include<bits/stdc++.h>
using namespace std;
int fun(int n)
{
	int cnt = 0;
	cnt += n / 100;
	n %= 100;
	cnt += n / 20;
	n %= 20;
	cnt += n / 10;
	n %= 10;
	cnt += n / 5;
	n %= 5;
	cnt += n;
	return cnt;
}
int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	cnt = fun(n);
	cout << cnt;
}
