#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void alloc(vector<int>& v, int size, int& mark)//���ڴ��Ϊv,markΪ��ǰ��ʶ��
{
	int flag = 0;
	int end = 0;
	for (int i = 0; i < v.size(); i++)//�����ڴ��,i�൱��ָ���ڴ�λ�õ�ָ�� 
	{
		if (v[i] == 0)//�ҵ�Ϊ�յ� 
		{
			int num = 0;//Ϊͳ�ƿյ����� 
			for (; i < v.size(); i++)
			{
				if (v[i] == 0)
					num++;
				else
					break;
				if (num == size)
				{
					end = i;
					flag = 1;//���Ԥ���Ĵ�С 
					break;
				}
			}
		}
		if (flag == 1)
			break;
	}
	if (flag == 0)
		cout << "NULL" << endl;
	else
	{
		mark++;
		end = end - size + 1;
		for (int i = end; i < end + size; i++)//����õ��ڴ�鸲�� 
			v[i] = mark;
		cout << mark << endl;
	}
}
void erase(vector<int>& v, int mark)//����ʶ����������� 
{
	bool flag = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == mark)
		{
			v[i] = 0;
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
}
void defragment(vector<int> &v)
{
	int n = v.size();
	for (int i = 0; i < v.size(); i++) 
	{
		if (v[i] == 0) 
		{
			v.erase(v.begin() + i);
			i--;
		}
	}
	while (v.size() < n)
		v.push_back(0);
}
int main()
{
	int t, m;
	cin >> t >> m;
	vector<int>v(m);
	string oper;
	int mark = 0;//���
	for (int i = 0; i < t; i++)
	{
		cin >> oper;//����
		if (oper == "defragment")
		{
			defragment(v);
		}
		else if (oper == "alloc")
		{
			int n;
			cin >> n;
			alloc(v, n, mark);
		}
		else
		{
			int n;
			cin >> n;
			erase(v, n);
		}
	}
}
