#include<bits/stdc++.h>
using namespace std;
int ret = 0;//Ҫ���ҵ���Ŀ������Ŀ
struct paper
{
	string pname;
	string name;
	int num;
};
void fun(string cs[],string s)//���ѯ�ʵ�ÿ������
{
	ret = 0;
	int i = 0;
	s += " ";
	int pos = s.find(" ");
	while (pos != -1)
	{
		ret++;
		cs[i] = s.substr(0, pos);
		s = s.substr(pos + 1, s.size());
		i++;
		pos = s.find(" ");
	}
}
bool com(paper a,paper b)//����
{
	return a.num > b.num;
}
int rfind(string a, string b)
{
	int i = 0;
	string s = a;
	s += " ";
	int pos = s.find(" ");
	while (pos != -1)
	{
		string com = s.substr(0, pos);
		if (com==b)
			break;
		s = s.substr(pos + 1, s.size());
		i++;
		pos = s.find(" ");
	}
	return pos;
}
int main()
{
	int n;
	while (cin >> n,n)
	{
		paper pp[10];
		for (int i = 0; i < n; i++)
		{
			cin.ignore();
			string s;
			getline(cin, s);
			pp[i].pname = s;
			transform(s.begin(), s.end(), s.begin(), ::tolower);
			int num;
			cin >> num;
			pp[i].name = s;
			pp[i].num = num;
		}
		int m;
		cin >> m;
		cin.ignore();
		for (int i = 0; i < m; i++)
		{
			string cs[15];
			string s;
			getline(cin, s);
			transform(s.begin(), s.end(), s.begin(), ::tolower);
			fun(cs, s);
			vector<paper>v;
			for (int i = 0; i < n; i++)//����ѭ��
			{
				int cnt = 0;//ͳ�Ʋ��ҵ��˼�����ͬ�ĵ���
				for (int j = 0; j < ret; j++)
				{
					int pos = rfind(pp[i].name, cs[j]);//�ж�һƪ�������Ƿ���ĳ������
					if (pos != -1)//�ҵ�
						cnt++;
				}
				if (cnt == ret)//������
					v.push_back(pp[i]);
			}
			sort(v.begin(), v.end(), com);
			if (v.empty())
			{
				cout << "***" << endl;
			}
			else
			{
				for (int i = 0; i < v.size(); i++)
					cout << v[i].pname << endl;
				cout << "***" << endl;
			}
		}
		cout << "---";
	}
}
