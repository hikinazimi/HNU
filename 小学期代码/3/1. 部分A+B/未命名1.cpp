#include<bits/stdc++.h>
using namespace std;
int cntc(string a, char b)
{
	int len = a.length();
	int cnt = 0;
	for (int i = 0; i < len; i++)
	{
		if (a[i] == b)
			cnt++;
	}
	return cnt;
}
int main()
{
	string A, B;
	char Da, Db;
	cin >> A >> Da >> B >> Db;
	string Pa( cntc(A, Da),Da);
	string Pb( cntc(B, Db),Db);
	long long int a, b;
	if (Pa.length() != 0)
		 a = stoll(Pa);
	else
		 a = 0;
	if (Pb.length() != 0)
		 b = stoll(Pb);
	else
		 b = 0;
	long long int c = a + b;
	cout << c;

}
