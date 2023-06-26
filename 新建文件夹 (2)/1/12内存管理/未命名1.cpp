#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void alloc(vector<int>& v, int size, int& mark)//设内存块为v,mark为当前标识符
{
	int flag = 0;
	int end = 0;
	for (int i = 0; i < v.size(); i++)//遍历内存块,i相当于指向内存位置的指针 
	{
		if (v[i] == 0)//找到为空的 
		{
			int num = 0;//为统计空的数量 
			for (; i < v.size(); i++)
			{
				if (v[i] == 0)
					num++;
				else
					break;
				if (num == size)
				{
					end = i;
					flag = 1;//获得预定的大小 
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
		for (int i = end; i < end + size; i++)//将获得的内存块覆盖 
			v[i] = mark;
		cout << mark << endl;
	}
}
void erase(vector<int>& v, int mark)//将标识符的数据清空 
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
	int mark = 0;//编号
	for (int i = 0; i < t; i++)
	{
		cin >> oper;//操作
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
