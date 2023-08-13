#include<iostream>
using namespace std;
int a[10100];
int b[10010];
int main()
{
	b[0] = 1;
	int temp = 1;
	for (int i = 0; i < 10001; )
	{
		for (int j = 0; j < temp; j++)
		{
			a[i] = temp;
			i++;
		}
		temp += 1;
	}

	for (int i = 1; i < 10001; i++)
	{
		b[i] = b[i - 1] + a[i];
	}
	int n;
	while(cin >> n)
	{
		cout << n<< " " << b[n - 1] << endl;
	}
}
