#include <bits/stdc++.h>
using namespace std;

//concept used : two node are in the same connected component iff it shared the same root 
//kruskal

vector<int> parent;
vector<int> rnk;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool unite(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb) return false; // check if already connected 

    if (rnk[pa] < rnk[pb]) swap(pa,pb); // choose lower rank 
    parent[pb] = pa; 
    if (rnk[pa] == rnk[pb]) rnk[pa]++; //prevent 0 1 rank

    return true;

}  

int main() {
    int v,e; cin >> v >> e;
    int ccnt = v;
    vector<bool> mem(v+1,0);
    rnk.resize(v+1, 0);

    parent.resize(v+1);
    for (int i=0 ;i<=v; i++) {
        parent[i] = i;
    }

    for (int i =0; i<e; i++) {
        int a,b; cin >> a >> b; 
        
        if (unite(a,b)) ccnt -= 1;
        
    }
    cout << ccnt;
}