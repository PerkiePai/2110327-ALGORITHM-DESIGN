#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e15;

int N,M,K;
vector<int> targets;
vector<vector<ll>> dist;
vector<bool> visited;
ll min_cost = INF;

void findPath(int cur_idx, int cnt, ll cur_cost) {
    if (cur_cost >= min_cost) return;

    if (cnt == K) {
        min_cost = min(min_cost, cur_cost);
        return;
    }

    for (int i=0; i<K; i++) {
        if (!visited[i]) {
            visited[i] = true;

            ll next_cost = (cnt == 0) ? 0 : cur_cost + dist[targets[cur_idx]][targets[i]];

            findPath(i, cnt+1, next_cost);

            visited[i] = false; 
        }
    }
}

int main() {
    cin >> N >> M >> K;

    targets.resize(K);
    for (int i=0; i<K; i++) {
        cin >> targets[i];
    }

    // set up floyd-warshall 1) dist[i][i] = 0; (visit to itself) 
    dist.resize(N+1, vector<ll>(N+1, INF));
    for (int i=1; i<=N; i++) {
        dist[i][i] = 0;
    }

    // get input
    for (int i=0; i<M; i++) {
        int u,v; cin >> u >> v;
        ll w; cin >> w;
        if (w<dist[u][v]) {
            dist[u][v] = dist[v][u] = w; //handle multiple edge
        }
    } 

    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            if (dist[i][k] == INF) continue;
            for (int j=1; j<=N; j++) {
                if (dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j] , dist[i][k]+dist[k][j]);
            }
        }
    }

    visited.assign(K, false);
    findPath(0,0,0);

    cout << min_cost;

}

