#include<iostream>
using namespace std;
#include <algorithm>
int a[10][10] = 
{
{73,74,75,76,77,78,79,80,81,82},
{72,43,44,45,46,47,48,49,50,83},
{71,42,21,22,23,24,25,26,51,84},
{70,41,20,7,8,9,10,27,52,85},
{69,40,19,6,1,2,11,28,53,86},
{68,39,18,5,4,3,12,29,54,87},
{67,38,17,16,15,14,13,30,55,88},
{66,37,36,35,34,33,32,31,56,89},
{65,64,63,62,61,60,59,58,57,90},
{100,99,98,97,96,95,94,93,92,91} 
};

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++)
	{
		int flag = 0;
		for (int j = 0; j < 10; j++)
		{
			if (a[i][j] <= n * n)
			{
				flag = 1;
				cout << a[i][j] << " ";
			}
		}
		if (flag == 1)
			cout << endl;
	}

}
