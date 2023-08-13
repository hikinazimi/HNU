#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<int, int,greater<int> >m;
	int a, b,cnt=0;
	while (cin >> a >> b)
	{
		if (a == 0 && b == 0)
			cnt++;
		if(cnt==2)
			break;
		m[a] += b;
	}
	for (map<int,int>::iterator it=m.begin();it!=m.end();it++)
	{
		if (it->second != 0)
			cout << it->first << ' ' << it->second << endl;
	}
}
