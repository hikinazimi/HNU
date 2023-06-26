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
    int jball;
    int ball;


    people()
    {
        name = "";
        score = 0;
        jball = 0;
        ball = 0;
    }

    people(string a, int b, int c,int d)
    {
        this->name = a;
        this->score = b;
        this->jball = c;
        this->ball = d;
    }
};
void fun(string a, int sc1, string b, int sc2, vector<people>&peo)
{
    int temp = abs(sc1 - sc2);
    people p1, p2;
    if (sc1 > sc2)
    {
        p1 = people (a, 3, temp,sc1);
        p2 = people(b, 0, -temp,sc2);
    }
    else if (sc1 == sc2)
    {
        p1 = people(a, 1, temp,sc1);
        p2 = people(b, 1, temp,sc2);
    }
    else
    {
        p1 = people(a, 0, -temp,sc1);
        p2 = people(b, 3, temp,sc2);
    }
        int ret1 = 0, ret2 = 0;
    for(vector<people>::iterator it = peo.begin();it<peo.end();it++)
    {

        if (it->name == p1.name)
        {
            it->score += p1.score;
            it->jball += p1.jball;
            it->ball += p1.ball;

            ret1 = 1;
        }
        if (it->name == p2.name)
        {
            it->score += p2.score;
            it->jball += p2.jball;
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
    else if (a.jball != b.jball)
        return a.jball > b.jball;
    else
        return a.ball > b.ball;

}
int main()
{
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<people>peo;
    string a, b, c;
    char t;
    int sc1, sc2;
    if (n == 2)
    {
        string tt;
        cin >> tt >> sc1 >> t >> sc2;
        int pos = tt.find("-");
        a = tt.substr(0, pos);
        b = tt.substr(pos + 1, tt.size());
        fun(a, sc1, b, sc2, peo);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                string tt;
                cin >> tt >> sc1 >> t >> sc2;
                int pos = tt.find("-");
                a = tt.substr(0, pos);
                b = tt.substr(pos + 1, tt.size());
                fun(a, sc1, b, sc2, peo);
            }
        }
    }
    sort(peo.begin(), peo.end(), com);
    vector<string>v;
    for (int i = 0; i < n / 2; i++)
        v.push_back(peo[i].name);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;

}

