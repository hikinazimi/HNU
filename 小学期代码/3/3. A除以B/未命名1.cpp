#include<bits/stdc++.h>
using namespace std;
int main()
{
	string A;
	int B;
	cin >> A >> B;
	int len = A.length();
	int a[len];
	for (int i = 0; i < len; i++)
		a[i] = A[i] - '0';
	int r = 0;
	vector<int>v;
	for (int i = 0; i < len; i++)
	{
		int temp = (a[i] + r * 10) / B;
		v.push_back(temp);
		r = (r * 10 + a[i]) % B;
	}
	if(v.size()==1||(v.size()>1&&v[0]!=0))
		cout<<v[0];
	for (int i = 1; i < v.size(); i++)
		cout<<v[i];
	cout << " " << r;
}
