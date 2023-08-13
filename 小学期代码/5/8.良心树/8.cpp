#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 100001
int p[MAXSIZE], c[MAXSIZE], d[MAXSIZE];
int n, m=0;
 
int main() {
    cin>>n;
    for (int i=1; i<=n; i++) cin>>p[i]>>c[i];
    for (int i=1; i<=n; i++) {
        if (c[i]==1) {
            int k=1;
            for (int j=1; j<=n; j++) 
                if (p[j]==i) k&=c[j];
            if (k==1) {
                for (int j=1; j<=n; j++) 
                    if (p[j]==i) p[j]=p[i];
                d[m++]=i;
            }
        }
    }
    if (m==0) cout<<-1;
    else 
        for (int i=0; i<m; i++) cout<<d[i]<<' ';
    return 0;
}

