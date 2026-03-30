#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, C, k; cin >> R >> C >> k;

    vector<vector<int>> mem(R+1, vector<int>(C+1, 0));
    vector<vector<int>> dist(R+1, vector<int>(C+1, -1));
    queue<pair<int,int>> q; //for start bfs
    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            cin >> mem[i][j];
            if (mem[i][j] == 1) {
                dist[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    int dirx[] = {1, -1, 0, 0};
    int diry[] = {0, 0, 1, -1};
    while (!q.empty()) {
        auto [ri,ci] = q.front(); q.pop();

        for (int i=0; i<4; i++) {
            int rn = ri+dirx[i];
            int cn = ci+diry[i];

            if (rn < 1 || rn > R || cn < 1 || cn > C) continue;
            if (mem[rn][cn] == 1) continue;
            if (dist[rn][cn] != -1) continue;

            dist[rn][cn] = dist[ri][ci] + 1;
            if ( dist[rn][cn] <= k ) {
                mem[rn][cn] = 2;
                q.push({rn,cn});
            }
        }

    }
    
    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            cout << mem[i][j] << " ";
        } cout << "\n";
    }


}