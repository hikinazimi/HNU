#include<bits/stdc++.h>
using namespace std;
int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int lmonth[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
string week[7] = { "Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
bool leap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}
int main()
{
	int n;
	while (cin >> n && n != -1)
	{
		int ret = n  % 7;
		int year = 2000, mon = 1, day = 1;
		while (n)
		{
			if (leap(year))
			{

				n--;
				day++;
				if (day > lmonth[mon])
				{
					day = 1;
					mon++;
				}
				if (mon > 12)
				{
					mon = 1;
					year++;
				}
			}
			else
			{
				n--;
				day++;
				if (day > month[mon])
				{
					day = 1;
					mon++;
				}
				if (mon > 12)
				{
					mon = 1;
					year++;
				}
			}
		}
		cout << year << '-' << setw(2)<<setfill('0') << mon << '-' << setw(2) << day << ' ';
		cout << week[ret] << endl;

	}
}
