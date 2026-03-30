#include <bits/stdc++.h>
using namespace std;

int N,E,K;
vector<vector<int>> adj(1001);

int bfs(int x) {
    vector<int> dist(N,-1);
    queue<int> q;
    dist[x] = 0;
    q.push(x);

    int cnt = 1;

    while (!q.empty()) {
        auto i = q.front(); q.pop();

        if (dist[i] == K) continue;

        for (auto v: adj[i]) {
            if (dist[v] != -1) continue;
            dist[v] = dist[i] + 1;
            cnt++;
            q.push(v);
        }
    }
    return cnt;
}

int main() {
    cin >> N >> E >> K;
    for (int i=0; i<E; i++) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }   

    int maxFriend = 0;
    for (int i=0; i<N; i++) {
        maxFriend = max(maxFriend, bfs(i));
    }
    cout << maxFriend;
}