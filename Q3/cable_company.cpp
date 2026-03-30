#include <bits/stdc++.h>
using namespace std;

//minimum spaning tree MST - Prim / Kruskal

int main() {
    int N; cin >> N;

    vector<vector<int>> mem(N, vector<int>(N, 0));

    for (int i=0; i<N-1; i++) {
        for (int j=i+1; j<N; j++) {
            cin >> mem[j][i];
            mem[i][j] = mem[j][i];
        }
    }

    //Prim - from graph find the minimun tree that can span with the lowest cost
    vector<int> cost(N, INT_MAX);
    vector<int> prev(N, -1);

    cost[0] = 0;

    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> pq;
    for (int u = 0; u<N; u++) {
        pq.push({cost[u] , u});
    }

    vector<bool> in_mst(N, false); //check is in mst 
    int total = 0; //total cost used 

    while (!pq.empty()) {
        auto [c, u] = pq.top(); pq.pop(); // c is cost of that edge, u = idx of that node which are processed 

        if (in_mst[u]) continue; //already in mst

        in_mst[u] = true;
        total += c;

        for (int v=0; v<N; v++) { // see which node v should be connect to the mst 
            if (!in_mst[v] && cost[v] > mem[v][u]) { // that node must not in mst and find the lowest v
                cost[v] = mem[v][u];
                prev[v] = u;
                pq.push({cost[v] , v});
            }
        }

    }

    cout << total;


}