#include <bits/stdc++.h>
using namespace std;

int main() {
    int R,C; cin >> R >> C;

    vector<vector<int>> mem(R,vector<int>(C));
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> mem[i][j];
        }
    }

    vector<vector<int>> dist(R,vector<int>(C, INT_MAX/4));
    dist[0][0] = 0;
    
    priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<>> pq;
    int di[] = {1,-1,0,0};
    int dj[] = {0,0,1,-1};
    pq.push({0,{0,0}});
    while (!pq.empty()) {
        auto [c,ij] = pq.top(); pq.pop();
        auto [ri,ci] = ij;

        for (int i=0; i<4; i++) {
            int rn = ri+di[i];
            int cn = ci+dj[i];

            if ( rn < 0 || rn > R-1 || cn < 0 || cn > C-1 ) continue;

            int nd = dist[ri][ci] + mem[rn][cn];
            if (nd < dist[rn][cn]) {
                dist[rn][cn] = nd;
                pq.push({nd, {rn, cn}}); // push total dist if it shorter 
            }

        }
    } 

    for (auto x: dist) {
        for (auto y: x) {
            cout << y << " ";
        } cout << "\n";
    }

}