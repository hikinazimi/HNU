#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<int>num;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		num.insert(a);
	}
	set<int>::iterator it = num.begin();
	for (int i = 0; i < k&&i<num.size(); i++)
	{
		cout << *it << " ";
		it++;
	}
}
