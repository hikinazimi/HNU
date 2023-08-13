#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 100001
#define STARTCITY 1
typedef struct 
{
    int citynum;
    pair<int, int> routine[MAXSIZE];
} Arabmap;
Arabmap m;
 
bool visited[MAXSIZE];
int leaves[MAXSIZE];
double rates[MAXSIZE];
int p=0;
 
void FindNearCities(vector<int> &v, int city) {
    for (int i=0; i<m.citynum-1; i++) {
        if (m.routine[i].first==city) v.push_back(m.routine[i].second);
        if (m.routine[i].second==city) v.push_back(m.routine[i].first);
    }
}
 
void DFS(int nowcity, int length, double rate) {
    visited[nowcity]=1; length++;
    vector<int> neighbors;
    FindNearCities(neighbors, nowcity);
    int size=(int)neighbors.size();
    if (size==1&&nowcity!=STARTCITY) {
        leaves[p]=length; rates[p]=rate;
        p++;
        return;
    }
    int childnum;
    for (int i=0; i<size; i++) {
        if (nowcity==STARTCITY) childnum=size;
        else childnum=size-1;
        if (!visited[neighbors[i]]) DFS(neighbors[i], length, rate/childnum);
    }
}
 
int main() {
    cin>>m.citynum;
    for (int i=0; i<m.citynum-1; i++) cin>>m.routine[i].first>>m.routine[i].second;
    DFS(STARTCITY, -1, 1);
    double E=0; p=0;
    while (leaves[p]) {
        E+=leaves[p]*rates[p];
        p++;
    }
    printf("%.7lf", E);
    return 0;
}

