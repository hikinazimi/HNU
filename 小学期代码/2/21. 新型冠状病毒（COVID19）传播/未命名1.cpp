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
    int mid;//�洢��Ÿ�Ⱦ�ߵ�λ��
    for (mid = 0; mid < n; mid++)
    {
        if (p[mid].v > lmaxv) lmaxv = p[mid].v;//����ٶ����ֵ
        if (p[mid].num == s) break;//�����ǰѡ������Ÿ�Ⱦ��
    }
    int safe = 0;//����δ��Ⱦ����
    int rminv = 1000000;//��ʼ��
    for (int i = mid; i < n; i++)
    {
        if (p[i].v >= lmaxv && p[i].pos > p[mid].pos)
            safe++;
        //����Ҳ�ѡ���ٶȴ�����ߵ�����ٶ�
        //���ұ�ѡ�ֵ�λ�ô�����Ÿ�Ⱦ�ߵ�λ��
        if (p[i].v < rminv) rminv = p[i].v;
        //�ҵ��ұ��ٶ���Сֵ
    }
    for (int i = 0; i < mid; i++)
    {
        if (p[i].v <= rminv && p[i].pos < p[mid].pos)
            safe++;
        //������ѡ���ٶ�С���ұߵ���С�ٶ�
        //�����ѡ�ֵ�λ��С����Ÿ�Ⱦ�ߵ�λ��
    }
    cout << n - safe << endl;
    //�����������ȥ��ȫ����
    system("pause");
    return 0;
}

