#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<int>> mem;

int bfs() {
    vector<vector<int>> dist(R+1, vector<int>(C+1, -1));
    queue<pair<int,int>> q;
    dist[1][1] = 0;
    q.push({1,1}); //starting point

    vector<pair<int,int>> dir = {{-1,0} , {1,0} , {0,-1} , {0,1}}; // up down left right 
    while (!q.empty()) {
        auto [r,c] = q.front(); q.pop();

        if (r == R && c == C) return dist[r][c];

        for (auto [dr , dc] : dir) {
            int nr = r+dr;
            int nc = c+dc;

            if (nr < 1 || nr > R || nc < 1 || nc > C) continue;
            if (mem[nr][nc] == 1) continue;
            if (dist[nr][nc] != -1) continue;

            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr,nc});

        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);  
    cin >> R >> C;

    mem.resize(R+1, vector<int>(C+1,-1));
    
    for (int i=1; i<=R ;i++) {
        string s; cin >> s;
        for (int j=1; j<=C; j++) {
            mem[i][j] = (s[j-1] == '#') ? 1 : 0;
        }
    }

    if (R == 1 && C == 1) {
        cout << 1;
        return 0;
    }
    if (mem[R][C] == 1) {
        cout << -1;
        return 0;
    }

    cout << bfs();
}