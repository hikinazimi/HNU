#include<bits/stdc++.h>
using namespace std;
int mint(int a, int b, int c) {
    return min(a, min(b, c));
}
int minDistance(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    int dp[20][20]={ 0 };
    // base case 
    for (int i = 1; i <= m; i++)
        dp[i][0] = i;
    for (int j = 1; j <= n; j++)
        dp[0][j] = j;
    // 自底向上求解
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = mint(
                    dp[i - 1][j] + 1,
                    dp[i][j - 1] + 1,
                    dp[i - 1][j - 1] + 1
                );
    // 储存着整个 s1 和 s2 的最小编辑距离
    return dp[m][n];
}

int main()
{
    vector<string>v;
    while(1)
    {
        string ss;
        getline(cin, ss);
        if (ss == "#")
            break;
        v.push_back(ss);
    }
    while (1)
    {
        string ss;
        getline(cin, ss);
        if (ss == "#")
            break;
        int flag = 0;
        vector<string>tv;
        for (int i = 0; i < v.size(); i++)
        {
            int ret=minDistance(v[i], ss);
            if (ret == 0)
            {
                flag = 1;
                break;
            }
            else if (ret == 1)
            {
                tv.push_back(v[i]);
                flag = 2;
            }
            else
                continue;
        }
        if (flag == 1)
            cout << ss << " is correct";
        else if (flag == 2)
        {
            cout << ss << ": ";
            for (int i = 0; i < tv.size(); i++)
                cout << tv[i] << " ";
        }
        else
            cout << ss << ":";
        cout << endl;
    }
}
