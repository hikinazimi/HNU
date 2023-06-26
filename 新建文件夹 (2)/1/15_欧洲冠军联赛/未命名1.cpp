#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
class people
{
public:
    string name;
    int score;
    int ball;

    people()
    {
        name = "";
        score = 0;
        ball = 0;
    }

    people(string a, int b, int c)
    {
        this->name = a;
        this->score = b;
        this->ball = c;
    }
};
void fun(string a, int sc1, string b, int sc2, vector<people>&peo)
{
    int temp = abs(sc1 - sc2);
    people p1, p2;
    if (sc1 > sc2)
    {
        p1 = people (a, 3, temp);
        p2 = people(b, 0, -temp);
    }
    else if (sc1 == sc2)
    {
        p1 = people(a, 1, temp);
        p2 = people(b, 1, temp);
    }
    else
    {
        p1 = people(a, 0, -temp);
        p2 = people(b, 3, temp);
    }
        int ret1 = 0, ret2 = 0;
    for(vector<people>::iterator it = peo.begin();it<peo.end();it++)
    {

        if (it->name == p1.name)
        {
            it->score += p1.score;
            it->ball += p1.ball;
            ret1 = 1;
        }
        if (it->name == p2.name)
        {
            it->score += p2.score;
            it->ball += p2.ball;
            ret2 = 1;
        }
    }
    if (ret1 == 0)
    {
        peo.push_back(p1);
    }
    if (ret2 == 0)
    {
        peo.push_back(p2);
    }
}
bool com(people a, people b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.ball > b.ball;

}
int main()
{
    int n;
    cin >> n;
    vector<people>peo;
    string a, b, c;
    int sc1, sc2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cin >> a >> sc1 >> c >> sc2 >> b;
            fun(a, sc1, b, sc2, peo);
        }
        sort(peo.begin(), peo.end(), com);
        cout << peo[0].name << " " << peo[1].name << endl;
        peo.clear();
    }
    
}

