#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string num;
	cin >> num;
	string tnum = num + num;
	int len = num.length();
	vector<char>tempc;
	int k = 0;
	int flag = 1;
	for (int i = 2; i <= len; i++)
	{
		int temp = 0;
		for (int j = len - 1; j >= 0; j--)
		{
			temp = (num[j] - '0') * i + temp;
			tempc.push_back(  temp % 10 + '0');
			temp /= 10;
		}
		reverse(tempc.begin(), tempc.end());
		
		string afstr;
		int size = tempc.size();
		for (int i = 0; i < size; i++)
			afstr.push_back(tempc[i]);
		tempc.clear();
		flag = tnum.find(afstr);
		afstr.clear();
		if (flag == -1)
			break;
		
	}
	if (flag == -1)
		cout << "No";
	else
		cout << "Yes";
}

