#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		int i = 0;
		while(n != 1)
		{
			if (n % 2 == 0)
				n /= 2;
			else
				n = (n * 3 + 1)/2;
			i++;
		}
		cout << i << endl;
	}
}
