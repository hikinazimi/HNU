#include<iostream>
using namespace std;
int mulit(int num)
{
	int temp = num / 2;
	int sum = 0;
	for (int i = 1; i <= temp; i++)
		if (num % i == 0)
			sum += i;
	return sum;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		int ta = mulit(a);
		int tb = mulit(b);
		if (ta == b && tb == a)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
