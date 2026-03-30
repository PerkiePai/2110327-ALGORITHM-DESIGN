#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> mem;
int xa,ya,xb,yb;

int bfs(int xa, int ya, int xb, int yb) {
    vector<vector<int>> dist(N+1, vector<int>(M+1, -1));
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{xa,ya}});
    dist[xa][ya] = 0;

    vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    while (!q.empty()) {
        auto [r,i] = q.front(); q.pop(); // r = 0 if it is no rocket

        auto [xi,yi] = i;

        if (xi == xb && yi == yb) return dist[xi][yi];

        if (mem[xi][yi] == 2) { //have rocket boost 
            for (int i=1; i<=N; i++) {
                int xn = xi + i;

                if ( xn < 1 || xn > N ) continue;
                if ( dist[xn][yi] != -1 ) { // already have distant 
                    if (dist[xi][yi] + 1 < dist[xn][yi]) {
                        dist[xn][yi] = dist[xi][yi] + 1;
                        q.push({ mem[xn][yi] , {xn,yi} });
                    }
                } else {
                    dist[xn][yi] = dist[xi][yi] + 1;
                    q.push({ mem[xn][yi] , {xn,yi} });
                }
            }
            for (int i=-1; i>=-N; i--) {
                int xn = xi + i;

                if ( xn < 1 || xn > N ) continue;
                if ( dist[xn][yi] != -1 ) { // already have distant 
                    if (dist[xi][yi] + 1 < dist[xn][yi]) {
                        dist[xn][yi] = dist[xi][yi] + 1;
                        q.push({ mem[xn][yi] , {xn,yi} });
                    }
                } else {
                    dist[xn][yi] = dist[xi][yi] + 1;
                    q.push({ mem[xn][yi] , {xn,yi} });
                }
            }
            for (int j=1; j<=M; j++) {
                int yn = yi + j;

                if ( yn < 1 || yn > M ) continue;
                if ( dist[xi][yn] != -1 ) { // already have distant 
                    if (dist[xi][yi] + 1 < dist[xi][yn]) {
                        dist[xi][yn] = dist[xi][yi] + 1;
                        q.push({ mem[xi][yn] , {xi,yn} });
                    }
                } else {
                    dist[xi][yn] = dist[xi][yi] + 1;
                    q.push({ mem[xi][yn] , {xi,yn} });
                }
            }
            for (int j=-1; j>=-M; j--) {
                int yn = yi + j;

                if ( yn < 1 || yn > M ) continue;
                if ( dist[xi][yn] != -1 ) { // already have distant 
                    if (dist[xi][yi] + 1 < dist[xi][yn]) {
                        dist[xi][yn] = dist[xi][yi] + 1;
                        q.push({ mem[xi][yn] , {xi,yn} });
                    }
                } else {
                    dist[xi][yn] = dist[xi][yi] + 1;
                    q.push({ mem[xi][yn] , {xi,yn} });
                }
            }
        } else { //normal
            
            for (auto [dirx,diry] : dir) {
                int xn = xi + dirx;
                int yn = yi + diry;
    
                if ( xn < 1 || xn > N || yn < 1 || yn > M ) continue;
                if ( mem[xn][yn] == 1 ) continue; // found block
                if ( dist[xn][yn] != -1 ) continue; // already have distant 
    
                dist[xn][yn] = dist[xi][yi] + 1;

                q.push({ mem[xn][yn] , {xn,yn} });

            }
        }
    }
    return -1;
}

int main() {
    cin >> N >> M;
    mem.resize(N+1, vector<int>(M+1));
    for (int i=1; i<=N; i++) {
        string s; cin >> s;
        for (int j=1; j<=M; j++) {
            int d;
            if (s[j-1] == '.') d = 0;
            else if (s[j-1] == 'X') d = 1;
            else if (s[j-1] == '#') d = 2;
            else if (s[j-1] == 'S') { // S to T
                xa = i;
                ya = j;
                d = 0;
            } else if (s[j-1] == 'T') {
                xb = i;
                yb = j;
                d = 0;
            } 
            mem[i][j] = d;
        }
    }
    cout << bfs(xa,ya,xb,yb);


}