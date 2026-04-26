#include <bits/stdc++.h>
using namespace std;

int R,C; 

struct Grid {
    vector<vector<int>> grid;
};

int main() {
    cin >> R >> C;
    Grid in;
    in.grid.assign(R, vector<int>(C));
    queue<pair<int,int>> startq;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> in.grid[i][j];
            if (in.grid[i][j] == 2) {
                startq.push({i,j});
                in.grid[i][j] = 0;
            }
        }
    }

    vector<Grid> mem;
    int dr[] = {1,-1,0,0};
    int dc[] = {0,0,1,-1};
    while (!startq.empty()) {
        auto start = startq.front(); startq.pop();

        queue<pair<int,int>> q;
        q.push(start);
        Grid dist;
        dist.grid.assign(R, vector<int>(C,-1));
        dist.grid[start.first][start.second] = 0;
        while (!q.empty()) {
            auto f = q.front(); q.pop();

            for (int i=0; i<4; i++) {
                int ir = f.first + dr[i];
                int ic = f.second + dc[i];

                if (ir<0 || ir>=R || ic<0 || ic>=C) continue;
                if (in.grid[ir][ic] == 1) continue;
                if (dist.grid[ir][ic] != -1) continue;

                dist.grid[ir][ic] = dist.grid[f.first][f.second] + 1;

                q.push({ir,ic});
            }

        }

        mem.push_back(dist);
    }

// Comparison Logic
    int cnt = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            bool allSame = true;
            for (size_t k = 1; k < mem.size(); k++) {
                if ( abs(mem[0].grid[i][j] - mem[k].grid[i][j]) > 1 ) {
                    allSame = false;
                    break;
                }
            }
            if (allSame && !mem.empty() && mem[0].grid[i][j] != -1) {
                cnt++;
            }
        }
    }
    cout << cnt;
    
}