#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a1, a2, a3, b1, b2, b3;
	char s;
	cin >> a1 >> s >> a2 >> s >> a3;
	cin >> b1 >> s >> b2 >> s >> b3;
	long long int sum =  (b1 * 17 * 29 + b2 * 29 + b3)-(a1 * 17 * 29 + a2 * 29 + a3 );
	if (sum >= 0)
	{
		cout << sum / 29 / 17 << "." << (sum / 29) % 17 << "." << sum % 29;
	}
	else
	{
		sum = -sum;
		cout << "-" << sum / 29 / 17 << "." << (sum / 29) % 17 << "." << sum % 29;
	}
}
