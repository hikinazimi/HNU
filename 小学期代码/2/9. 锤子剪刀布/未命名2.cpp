#include<iostream>
using namespace std;
char a[3] = { 'B','C','J' };
class people
{
public:
	char s;
	int a[3];
	int b[3];
	people()
	{
		s = ' ';
		for (int i = 0; i < 3; i++)
		{
			a[i] = 0;
			b[i] = 0;
		}
	}
};
people G, Y;

void fun(char t1,char t2)
{
	if (t1 == t2)
	{
		G.a[1]++;
		Y.a[1]++;
	}
	else if ((t1=='C'&&t2=='J')||(t1=='J'&&t2=='B')||(t1=='B'&&t2=='C'))
	{
		G.a[0]++;
		Y.a[2]++;
		if (t1 == 'C')
			G.b[1]++;
		else if (t1 == 'J')
			G.b[2]++;
		else
			G.b[0]++;
	}
	else
	{
		G.a[2]++;
		Y.a[0]++;
		if (t2 == 'C')
			Y.b[1]++;
		else if (t2 == 'J')
			Y.b[2]++;
		else
			Y.b[0]++;
	}
}
void com(people p)
{
	int max = -1;
	char s;
	for (int i = 0; i < 3; i++)
	{
		if (p.b[i] > max)
		{
			max = p.b[i];
			s = a[i];
		}
	}
	cout << s << " ";
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char t1, t2;
		cin >> t1 >> t2;
		fun(t1, t2);
	}
	cout << G.a[0] << " " << G.a[1] << " " << G.a[2] << endl;
	cout << Y.a[0] << " " << Y.a[1] << " " << Y.a[2] << endl;
	com(G);
	com(Y);


}
