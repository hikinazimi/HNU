#include <bits/stdc++.h>
using namespace std;
const int  N = 2002;
 int lc(int u) {return u << 1;}
 int rc(int u) {return u << 1 | 1;}
 int lowbit(int x) {return x & (-x);}
long long a[N][N];
int n, m, w;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
void bfs(int st, int ed, vector<vector<long long > > &d) {
    queue<pair<int,int> > q;
    d[st][ed] = 0;
    q.push({st, ed});
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++ ) {
            int x = t.first + dx[i];
			int y = t.second + dy[i];
            if (x < 1 || x > n || y < 1 || y > m || d[x][y] != -1 || a[x][y] == -1) continue;
            d[x][y] = d[t.first][t.second] + 1;
            q.push({x, y});
        }
    }
}
 void solve() {
    cin >> n >> m >> w;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) cin >> a[i][j];
    }
    vector<vector<long long>> d1(n + 1, vector<long long> (m + 1, -1));
    vector<vector<long long>> d2(n + 1, vector<long long> (m + 1, -1));
    bfs(1, 1, d1);
    bfs(n, m, d2);
    long long best_ed = LLONG_MAX;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            if (d2[i][j] != -1 && a[i][j] >= 1) {
                best_ed = min(best_ed, d2[i][j] * w * 1ll + a[i][j]);
            }
        }
    }
   long long res = w * 1ll * d1[n][m];
    if (d1[n][m] == -1) res = LLONG_MAX;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            if (d1[i][j] != -1 && a[i][j] >= 1 && best_ed != LLONG_MAX) {
                res = min(res, w * 1ll * d1[i][j] + a[i][j] + best_ed);
            }
        }
    }
    if (res == LLONG_MAX) cout << -1 << endl;
    else cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
        solve();
    return 0;
}

