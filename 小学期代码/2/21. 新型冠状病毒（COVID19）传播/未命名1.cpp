#include<iostream>
#include<algorithm>
using namespace std;

struct people
{
    int num;
    int pos;
    int v;
};

bool cmp(const people a, const people b)
{
    if (a.pos == b.pos)
    {
        return a.v > b.v;
    }
    return a.pos < b.pos;
}

const int N = 10000500;
people p[N];

int main()
{
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].pos;
        p[i].num = i + 1;
    }
    for (int i = 0; i < n; i++)
        cin >> p[i].v;
    sort(p, p + n, cmp);
    int lmaxv = -1;
    int mid;//存储零号感染者的位置
    for (mid = 0; mid < n; mid++)
    {
        if (p[mid].v > lmaxv) lmaxv = p[mid].v;//左边速度最大值
        if (p[mid].num == s) break;//如果当前选手是零号感染者
    }
    int safe = 0;//储存未感染人数
    int rminv = 1000000;//初始化
    for (int i = mid; i < n; i++)
    {
        if (p[i].v >= lmaxv && p[i].pos > p[mid].pos)
            safe++;
        //如果右侧选手速度大于左边的最大速度
        //且右边选手的位置大于零号感染者的位置
        if (p[i].v < rminv) rminv = p[i].v;
        //找到右边速度最小值
    }
    for (int i = 0; i < mid; i++)
    {
        if (p[i].v <= rminv && p[i].pos < p[mid].pos)
            safe++;
        //如果左边选手速度小于右边的最小速度
        //且左边选手的位置小于零号感染者的位置
    }
    cout << n - safe << endl;
    //输出总人数减去安全人数
    system("pause");
    return 0;
}

