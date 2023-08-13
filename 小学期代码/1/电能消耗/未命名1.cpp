#include<iostream>
using namespace std;
int fun(int p1, int p2, int p3, int t1, int t2, int s)
{
	int sum = 0;
	if (s < t1)
	{
		sum = s * p1;
	}
	else if (s < t2+t1)
	{
		sum = p1 * t1 + p2 * (s - t1);
	}
	else
	{
		sum = p1 * t1 + p2 * t2 + p3 * (s - t1 - t2);
	}
	return sum;
}
int main()
{
	int n, p1, p2, p3, t1, t2;
	cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
	int time[2 * n];
	for (int i = 0; i < 2*n; i++)
	{
		cin >> time[i];
	}
	int sum = 0;
	for (int i = 0; i < 2 * n-1; i++)
	{
		int temp = time[i + 1] - time[i];
		if (i % 2 == 0)
		{
			sum += p1 * temp;
		}
		else
		{
			sum += fun(p1, p2, p3, t1, t2, temp);
		}
	}
	cout << sum;
}
