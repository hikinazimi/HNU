#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int sum[10] = { 25,18,15,12,10,8,6,4,2,1 };
class people
{
public:
    string name;
    int score;//·ÖÊý
    int a[100];

    people()
    {
        this->name = "";
        this->score = 0;
        for (int i = 0; i < 100; i++)
            a[i] = 0;
    }

    people(string a, int b,int c)
    {
        this->name = a;
        this->score = b;
        this->a[c] = 1;
        for (int i = 0; i < 100; i++)
        {
            if (i == c)
                this->a[i] = 1;
            else
                this->a[i] = 0;
        }
    }
};
void fun(string a, int sc1,vector<people>&peo)
{
    int itscore = sum[sc1];
    people p = people(a, itscore, sc1);
    int ret = 0;
    for (vector<people>::iterator it = peo.begin(); it < peo.end(); it++)
    {
        if (it->name == a)
        {
            it->score += itscore;
            it->a[sc1]++;
            ret = 1;
            break;
        }
    }
    if (ret == 0)
        peo.push_back(p);
}
bool com1(people pre, people aft)
{
    int i = 0;
    if (pre.score != aft.score)
        return pre.score > aft.score;
    else
    {
        while (1)
        {
            if (pre.a[i] != aft.a[i])
                return pre.a[i] > aft.a[i];
            i++;
        }
    }
}
bool com2(people pre, people aft)
{
    int i = 1;
    if (pre.a[0] != aft.a[0])
        return pre.a[0] > aft.a[0];
    else if (pre.score != aft.score)
        return pre.score > aft.score;
    else
    {
        while (1)
        {
            if (pre.a[i] != aft.a[i])
                return pre.a[i] > aft.a[i];
            i++;
        }
    }

}
int main()
{
    int n;
    cin >> n;
    vector<people>peo;
    string s;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> s;
            fun(s, j, peo);
        }
    }
    sort(peo.begin(), peo.end(), com1);
    cout << peo[0].name << endl;
    sort(peo.begin(), peo.end(), com2);
    cout << peo[0].name;
}

