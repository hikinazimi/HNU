#include<bits/stdc++.h>
using namespace std;
int trs(string s) 
{
	if (s == "N")
		return -1;
	else
	{
		string a = s.substr(1, s.size() - 1);
		int b = stoi(a);
		return b;
	}
}
int main()
{
	int n, A, B, C;
	while (cin >> n >> A >> B >> C)
	{
		int card[n];
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			if (trs(s) == -1)
				card[i] = 0;
			else
				card[i] = trs(s);
		}
		int sum[1000];
		sum[0] = (A * C + B) % 6 + 1;
		for (int i = 1; i < 1000; i++)
		{
			sum[i] = (A * sum[i - 1] + B) % 6 + 1;
		}
		int Lele = 0, Yueyue = 0;
		int i = 0;
		while (1)
		{
			//Lele�Ļغ�
			Lele += sum[i];
			if (Lele == n - 1)//������յ�
			{
				cout << "Lele" << endl;
				break;
			}
			if (Lele > n - 1)//�����յ�,
			{
				Lele = 2*n - 2 - Lele;
			}
			if (card[Lele] != 0)//�ж��Ƿ�Ϊ����λ��
				Lele = card[Lele];
			if (Lele == Yueyue)//�������,�ص����
				Lele = 0;
			//Yueyue�Ļغ�
			i++;
			Yueyue += sum[i];
			if (Yueyue == n - 1)//������յ�
			{
				cout << "Yueyue" << endl;
				break;
			}
			if (Yueyue > n - 1)//�����յ�,
			{
				Yueyue = 2 * n - 2 - Yueyue;
			}
			if (card[Yueyue] != 0)//�ж��Ƿ�Ϊ����λ��
				Yueyue = card[Yueyue];
			if (Lele == Yueyue)//�������,�ص����
				Yueyue = 0;
			i++;
		}
	}
}
