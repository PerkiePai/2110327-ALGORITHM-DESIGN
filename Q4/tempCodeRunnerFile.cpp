#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<int> state;
    int empty_pos;
};


int main() {
    int N,M; cin >> N >> M;
    vector<vector<int>> adj(2*N+2);
    for (int i=0; i<M; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> startS(2*N+2), targetS(2*N+2); 
    for (int i=1; i<=N; i++) {
        startS[i] = (1); // 1 = red
        targetS[i] = (2); // 2 = blue
    }
    for (int i=N+1; i<=2*N; i++) {
        startS[i] = (2); // 2 = blue
        targetS[i] = (1); // 1 = red
    }
    startS[2*N+1] = 0; // 0 = empty
    targetS[2*N+1] = 0; // 0 = empty

    queue<Node> q;
    q.push({startS, 2*N+1});

    //map state -> { parent_state , move_made }
    map<vector<int> , pair<vector<int>, int>> parent;
    parent[startS] = {startS, -1};

    bool found = false;
    while (!q.empty()) {
        Node current = q.front(); q.pop();

        if (current.state == targetS) {
            found = true;
            break;
        }

        int empty_idx = current.empty_pos;

        for (int neighbor: adj[empty_idx]) {
            vector<int> nextS = current.state;
            swap(nextS[empty_idx] , nextS[neighbor]);

            if (parent.find(nextS) == parent.end()) { // nextS is new state
                parent[nextS] = {current.state , neighbor};
                q.push({nextS, neighbor});
            }
        }
    }

    if (!found) {
        cout << -1;
    } else {
        vector<int> path;
        vector<int> curr = targetS;

        while (parent[curr].second != -1) {
            path.push_back(parent[curr].second);
            curr = parent[curr].first;
        }

        cout << path.size() << endl;
        for (int i=path.size(); i>=0; i--) {
            cout << path[i] << " ";
        }
    }
}