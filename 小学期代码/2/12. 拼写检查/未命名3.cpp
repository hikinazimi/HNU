#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<int, vector<string> >dict;
	string s;
	while (cin >> s)
	{
		if (s == "#")
			break;
		int len = s.length();
		dict[len].push_back(s);
	}
	while (cin >> s)
	{
		set<string>setr;
		if (s == "#")
			break;
		int len = s.length();
		vector<string>::iterator pos = find(dict[len].begin(), dict[len].end(), s);
		if (pos != dict[len].end())//�ҵ����ֵ
		{
			cout << *pos << " is correct" << endl;
			continue;
		}
		for (int i = 0; i < len; i++)//�޸ĵ���ֵ
		{
			string ss = s;
			for (int j = 0; j < 26; j++)
			{
				ss[i] = j + 'a';
				vector<string>::iterator pos = find(dict[len].begin(), dict[len].end(), ss);
				if (pos != dict[len].end())
					setr.insert(ss);
			}
		}
		if (len > 1)//ɾ��
		{
			for (int i = 0; i < len; i++)
			{
				string ss = s;
				ss.erase(i + ss.begin());
				vector<string>::iterator pos = find(dict[len - 1].begin(), dict[len].end(), ss);
				if (pos != dict[len - 1].end())
					setr.insert(ss);

			}
		}
		for (int i = 0; i <= len; i++)//���
		{
			for (int j = 0; j < 26; j++)
			{
				string ss = s;
				char temp = j + 'a';
				ss.insert(i, 1,temp);
				vector<string>::iterator pos = find(dict[len + 1].begin(), dict[len].end(), ss);
				if (pos != dict[len + 1].end())
					setr.insert(ss);
			}
		}
		
	}
}
