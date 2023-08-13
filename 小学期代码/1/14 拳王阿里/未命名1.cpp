#include<iostream>
#include<string>
using namespace std;
string week[] = { "0","monday","tuesday","wednesday","thursday","friday","saturday","sunday" };
void fun(string a, string b, int pre, int end)
{
    int t1, t2;
    for (int i = 1; i < 8; i++)
    {
        if (a == week[i])
            t1 = i;
        if (b == week[i])
            t2 = i;
    }
    int temp = t2 - t1 + 1;
    if (temp <= 0)
        temp += 7;
    int cnt = 0;
    int ans;
    for (int i = pre; i <= end; i++)
    {
        if (i % 7 == temp % 7)
        {
            cnt++;
            ans = i;
        }

    }
    if (cnt == 0)
        cout << "impossible" << endl;
    else if (cnt == 1)
        cout << ans << endl;
    else
        cout << "many" << endl;
}
int main()

{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        int pre, end;
        cin >> a >> b >> pre >> end;
        fun(a, b, pre, end);
    }
}


