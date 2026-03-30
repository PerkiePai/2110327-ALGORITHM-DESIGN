#include <bits/stdc++.h>
using namespace std;

//Kahn's Algo 

int main() {
    int N; cin >> N;

    vector<vector<int>> adj(N);
    vector<int> in_deg(N, 0);

    for (int i=0 ;i<N ;i++) {
        int d; cin >> d;
        for (int j=0; j<d; j++) {
            int dd; cin >> dd;
            adj[i].push_back(dd);
            in_deg[dd]++;
        }
    }

    queue<int> q;
    for (int i=0; i<N; i++) {
        if (in_deg[i] == 0) q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);

        for (int v: adj[u]) {
            in_deg[v]--; 
            if (in_deg[v] == 0) q.push(v);
        }   
    }


    for (int i=order.size()-1 ; i>=0; i--) {
        cout << order[i] << " ";
    }

}