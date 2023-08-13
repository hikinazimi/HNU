#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 200000
#define START 1
 
int n; 
typedef struct nearspot
{
	int npt;
	nearspot* next;
} nearspot;
 
nearspot* arc[MAXSIZE];
 
int visited[MAXSIZE];
int given[MAXSIZE];
int result[MAXSIZE], ptr=0;
 
 
void FindNearSpots(int child[], int &num, int s) {
	nearspot* p=arc[s];
	while (p) {
		if (!visited[p->npt]) child[num++]=p->npt;
		p=p->next;
	}
}
 
bool cmp(int l, int r) {
	int ln=0, rn=0;
	for (int i=0; i<n; i++) {
		if (given[i]==l) ln=i;
		if (given[i]==r) rn=i;
	}
	return ln<rn;
}
 
void visit(int s) {
	visited[s]=1;
	result[ptr++]=s;
}
 
void DFS(int start) {
	queue<int> q; q.push(start);
	int child[MAXSIZE]; int num=0, s;
	while (!q.empty()) {
		s=q.front(); q.pop();
		visit(s);
		FindNearSpots(child, num, s);
		sort(child, child+num, cmp);
		for (int i=0; i<num; i++) q.push(child[i]);
		num=0;
	}
}
 
void Insert(int host, int neighbor) {
	nearspot* p=new nearspot;
	p->next=arc[host]; p->npt=neighbor;
	arc[host]=p;
}
 
int main() {
	cin>>n;
	int a, b;
	for (int i=1; i<=n; i++) arc[i]=NULL;
	for (int i=0; i<n-1; i++) {
		cin>>a>>b;
		Insert(a, b); Insert(b, a);
	}
	for (int i=0; i<n; i++) cin>>given[i];
	DFS(START);
	ptr=1;
	for (int i=0; i<n; i++) 
		if (given[i]!=result[i]) {ptr=0; break;}
	if (ptr) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
