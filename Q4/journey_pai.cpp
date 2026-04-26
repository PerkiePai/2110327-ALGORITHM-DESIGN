#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mem[(1<<20)][20];
int adj[20][20];

int main() {
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> adj[i][j];
        }
    }

    for (int i=0; i<(1<<N); i++) {
        for (int j=0; j<N; j++) {
            mem[i][j] = -1e18;
        }
    }

    mem[1][0] = 0;

    for (int mask = 1; mask<(1<<N); mask++) {
        for (int u = 0; u<N; u++) {
            if ((mask & (1<<u)) && (mem[mask][u] != -1e18)) {
                if ( (u==N-1) && (mask != (1<<N)-1) ) continue;

                for (int v=0; v<N; v++) {
                    if (!(mask & (1<<v))) {
                        int next_mask = (mask | (1<<v));
                        mem[next_mask][v] = max(mem[next_mask][v] , mem[mask][u] + adj[u][v]);
                    }
                }

            }
        }
    }

    cout << mem[(1<<N)-1][N-1];
}