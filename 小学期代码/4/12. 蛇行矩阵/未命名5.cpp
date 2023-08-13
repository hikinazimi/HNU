#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int main()
{
	a[0][1] = 1;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		a[i][1] = a[i - 1][1] + i-1;
		int ret = i + 1;
		for (int j = 1; j <= n - i + 1; j++)
		{
			cout << a[i][j] << " ";
			a[i ][j+1] = a[i][j] + ret;
			ret++;
		}
		cout << endl;
	}
	
}
