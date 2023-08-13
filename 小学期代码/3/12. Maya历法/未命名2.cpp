#include<bits/stdc++.h>
using namespace std;
struct Maya
{
	int n;
	string name;
};
string Tname[20] =
{ "imix","ik","akbal","kan","chicchan","cimi",
"manik","lamat","muluk","ok","chuen","eb","ben",
"ix","mem","cib","caban","eznab","canac","ahau" 
};
string Hname[18] =
{
"pop", "no","zip","zotz","tzec","xul","yoxkin","mol","chen",
"yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu"
};
int trans(string s)
{
	int pos = s.find(".");
	string a = s.substr(0, pos);
	string b = s.substr(pos + 1, s.length());
	int sum = stoi(a) + 1;
	if (b == "uayet")
		sum += 360;
	else
	{
		int i = 0;
		for (; i < 18; i++)
		{
			if (Hname[i] == b)
				break;
		}
		sum += i * 20;
	}
	return sum;
}
int main()
{
	vector<Maya>Tyear;
	Maya tt;
	tt.n = 13;
	tt.name = "ahau";
	Tyear.push_back(tt);
	int i = 1, j = 0;
	while (1)//Tzolkin£¨¶¬ÇàÄê£©
	{
		Maya temp;
		temp.n = i;
		temp.name = Tname[j];
		Tyear.push_back(temp);
		i++; j++;
		if (i > 13)
			i = 1;
		if (j >= 20)
			j = 0;
		if (i == 1 && j == 0)
			break;
	}
	Tyear;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string month;
		int year;
		cin >> month >> year;
		int sum = trans(month) + year * 365;
		int Ty = sum / 260;
		int tm = sum % 260;
		cout << Tyear[tm].n << " " << Tyear[tm].name << " " << Ty << endl;

	}
}
