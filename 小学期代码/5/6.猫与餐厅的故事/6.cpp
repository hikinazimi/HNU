#include <bits/stdc++.h>
using namespace std;
#define max 200001
#define STARTSPOT 1
typedef struct 
{
    int parknum;
    bool cat[max];
    pair<int, int> arr[max];
} Graph;
Graph g;
int m, OK=0;
bool visited[max];
 
 
void Find_ns(vector<int> &ns, int v) {
    for (int i=0; i<g.parknum-1; i++) {
        if (g.arr[i].first==v) ns.push_back(g.arr[i].second);
        if (g.arr[i].second==v) ns.push_back(g.arr[i].first); 
    }
}
 
void DFS(int v, int c, bool f) {
    visited[v]=1;
    if (f) {
        if (g.cat[v]) c++;
        else c=0;
        if (c>m) f=0;
    }
    vector<int> ns;
    Find_ns(ns, v);
    int size=(int)ns.size();
    if (size==1&&v!=STARTSPOT) {
        if (f) OK++;
        return;
    }
    for (int i=0; i<size; i++) 
        if (!visited[ns[i]]) DFS(ns[i], c, f);
}
int main() {
    cin>>g.parknum>>m;
    for (int i=1; i<=g.parknum; i++) cin>>g.cat[i];
    for (int i=0; i<g.parknum-1; i++) cin>>g.arr[i].first>>g.arr[i].second;
    DFS(STARTSPOT, 0, 1);
    cout<<OK<<endl;
    return 0;
}

