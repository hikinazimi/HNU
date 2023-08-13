#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, w;
	int sum = 0;
	cin >> n >> w;
	int min = 0;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		sum += temp;
		if (sum > max)
			max = sum;
		if (sum < min)
			min = sum;
	}
	int t = w - max + min + 1;
	if(t<0)
		cout<<0;
	else
		cout<<t;
}
