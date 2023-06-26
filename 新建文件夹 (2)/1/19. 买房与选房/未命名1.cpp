#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
using namespace std;

struct people
{

	char id[19];                  /* ���֤���� */

	int social;                     /* �籣�������� */

	int area;                       /* ����ס����� */

	char date[11];              /* �걨���� */

};

people* getMess(int& n);


struct human
{
	string name;  //���� 
	int months;    //��סʱ�� �·� 
	int S;			//��ס��� 
	int time;		//�ύ�����ʱ�� 

	int rank;     	//���򷿵������������� 
	int has_house;  //�Ƿ��ܹ��� 
	int remain;		//�������ʱ���ж��ٷ� 

	human() {
		has_house = 1;  //Ĭ���ܹ��� 
	}

};


bool cmp(human a, human b) {
	if (a.has_house != b.has_house)
	{
		return a.has_house > b.has_house;
	}  //�����򷿵��ں��� 

	if (a.S == 0 && b.S == 0)   //������ 
	{
		if (a.months != b.months)
		{
			return a.months > b.months;
		}    //�ȱȽϾ�ס�·� 
		else
		{
			return a.time < b.time;
		}    //���Ƚ��ύ�����ʱ�� 
	}

	if (a.S != b.S)
	{
		return a.S < b.S;
	}   //�ȽϾ�ס�����С������ 
	else {
		return a.time < b.time;		//���ύ��������� 
	}
}


int main()
{

	people* person;          /* ָ�����б����˵Ļ��������׵�ַ��ͨ�����ú���getMess��ȡ */
	int n;                            /* nΪ����������ͨ�����ú���getMess��ȡ */
	person = getMess(n);

	int no_house = 0;          //�����޷��򷿵����� 
	human* h = new human[n];

	for (int i = 0; i < n; i++) {
		h[i].name = person[i].id;	  //���֤ 
		//cout<<h[i].name;
		h[i].months = person[i].social;  //���� 
		h[i].S = person[i].area;

		if (h[i].S == 0 && h[i].months <= 24) {   //�޷��򷿵��� 
			h[i].has_house = 0;
			no_house++;
		}

		string temp = person[i].date;


		h[i].time = (temp[0] - '0') * 10 * 30 + (temp[1] - '0') * 30 +
			(temp[3] - '0') * 10 + (temp[4] - '0') +
			(temp[6] - '0') * 1000 * 365 + (temp[7] - '0') * 100 * 365 + (temp[8] - '0') * 10 * 365 + (temp[9] - '0') * 365;

	}


	sort(&h[0], &h[n], cmp);  


	int m;
	int T;
	cin >> m >> T;

	int num = n - no_house;

	for (int i = 0; i < num; i++)       //������λ�����Լ��ܷ������� 
	{
		h[i].rank = i + 1;

		if (i > 0) {                                          // ȫ��Ҫ�Ƚϣ������� 
			if (h[i].S == 0 && h[i - 1].S == 0) {
				if (h[i].months == h[i - 1].months && h[i].time == h[i - 1].time)
				{
					h[i].rank = h[i - 1].rank;
				}
			}
			else if (h[i].S == h[i - 1].S && h[i].S != 0 && h[i - 1].S != 0) {
				if (h[i].time == h[i - 1].time) {

					h[i].rank = h[i - 1].rank;
				}
			}
		}



	}

	for (int i = 0; i < num; i++) { h[i].remain = m - i; }   //ÿ���˵�ʣ���ѡ����   	

	while (T--) {
		string a_name;
		cin >> a_name;

		int pos = 0;
		for (int i = 0; i < n; i++)
		{

			if (h[i].name == a_name)     
			{
				pos = i;
				break;
			}
		}
		if (h[pos].has_house == 0) {    //����û���򷿵ĸ������� 
			cout << "Sorry" << '\n';
		}
		else {

			int num_house = 0;
			int num_same_rank = -1;

			for (int i = pos; i < num; i++) {           //��������ͬλ�ε� 
				if (h[i].rank != h[pos].rank) break;
				else {
					num_same_rank++;
				}
			}

			for (int i = pos; i >= 0; i--) {           //��������ͬλ�ε� 
				if (h[i].rank == h[pos].rank) {
					num_house = h[i].remain;
					num_same_rank++;
				}
				else break;
			}

			if (num_same_rank == 1) {                        //��λ��ֻ��һ���� 
				if (num_house <= 0) cout << "Sorry" << '\n';
				else cout << h[pos].rank << '\n';
			}
			else {

				if (num_house <= 0) cout << "Sorry" << '\n';
				else if (num_house >= num_same_rank) {           //��������㹻  
					cout << h[pos].rank << " " << h[pos].rank + num_same_rank - 1 << '\n';
				}
				else {
					cout << num_house << "/" << num_same_rank << '\n';
				}
			}
		}
	}
	return 0;

}

people* getMess(int& n)            /* ���ļ����ݶ����ڴ� */

{

	FILE* fp;

	fp = fopen("house.bin", "rb");


	fseek(fp, -1 * (long)sizeof(int), 2);

	fread(&n, sizeof(int), 1, fp);

	rewind(fp);

	people* tmp = new people[n];

	fread(tmp, sizeof(people), n, fp);


	fclose(fp);

	return tmp;

}
