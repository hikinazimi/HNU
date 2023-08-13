#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int main()
{
    int n;
    while (cin >> n && n) {
        int sum[n * (n - 1) / 2], all = n * (n - 1) / 2;
        for (int i = 0; i < all; ++i) {
            cin >> sum[i];
        }
        for (int k = 2; k < all; ++k) { 
            int num[n + 5];
            bool vis[all];
            memset(num,0,sizeof(num));
            memset(vis,0,sizeof(vis));
            if ((sum[0] + sum[1] - sum[k]) % 2 || (sum[0] + sum[1] - sum[k] <= 0)) 
                continue;
            num[0] = (sum[0] + sum[1] - sum[k]) / 2;
            num[1] = (sum[0] - num[0]);
            num[2] = (sum[1] - num[0]);
            vis[0] = vis[1] = vis[k] = 1;
            int know = 2;
            bool flag = 1; 
            while (know != n - 1) { 
                int in = -1;
                for (int i = 0; i < all; ++i) {
                    if (vis[i] == 0) {
                        in = sum[i];
                        vis[i] = 1;
                        break;
                    }
                }
                num[++know] = in - num[0];
                for (int i = 1; i < know; ++i) {
                    int he = num[know] + num[i];
                    flag = 0;
                    for (int j = 0; j < all; ++j) {
                        if (vis[j] == 0 && sum[j] == he) {
                            vis[j] = 1;
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) break;
                }
                if (flag == 0) break;
            }
            if (know != n - 1) continue;
            for (int i = 0; i < n; ++i) {
                cout << num[i] << ' ';
            }
            cout << endl;
            break;
        }
    }
}


