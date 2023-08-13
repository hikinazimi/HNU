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
	int day;
	while (cin >> day, day != -1)
	{

		int year = 2000;
		string s = week[day % 7];
		while (day > 0)
		{
			if (leap(year))
				day -= 366;
			else
				day -= 365;
			year++;
		}
		year--;
		day++;
		int j;
		if (leap(year))
		{
			day += 366;
			for (j = 1; j <= 12; j++)
			{
				if (day > lmonth[j])
					day -= lmonth[j];
				else
					break;
			}
		}
		else
		{
			day += 365;
			for (j = 1; j <= 12; j++)
			{
				if (day > month[j])
					day -= month[j];
				else
					break;
			}
		}
		if (j == 13)
		{
			year++;
			j = 1;
		}
		cout << year << "-";
		cout << setw(2) << setfill('0') << j << "-" << setw(2) << setfill('0') << day << " ";
		cout << s << endl;


	}
}
