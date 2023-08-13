#include<iostream>
#include<iomanip>
using namespace std;
double score(int sc)
{
	if (89 < sc && sc < 101)
		return 4.0;
	else if (84 < sc && sc < 90)
		return 3.7;
	else if (81 < sc && sc < 85)
		return 3.3;
	else if (77 < sc && sc < 82)
		return 3.0;
	else if (74 < sc && sc < 78)
		return 2.7;
	else if (71 < sc && sc < 75)
		return 2.3;
	else if (67 < sc && sc < 72)
		return 2.0;
	else if (63 < sc && sc < 68)
		return 1.5;
	else if (59 < sc && sc < 64)
		return 1.0;
	else
		return 0;
}
int main()
{
	int n;
	cin >> n;
	int  num[5];
	int sc;
	double sum = 0;
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		temp += num[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> sc;
		sum += num[i] * score(sc);
	}
	sum /= temp;
	cout << setprecision(2) << fixed << sum;

}
