#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mem[1<<20][20]; //mem [ #bitmask of bit 1 tell places already visited ] [ last place u stand ] = max of all path 
int adj[20][20];

int main() {
    int n; cin >> n;
    for (int i=0; i<n; i++) { //input
        for (int j=0; j<n; j++) {
            cin >> adj[i][j];
        }
    }

    for (int i=0; i<(1<<n); i++) {
        for (int j=0; j<n; j++) {
            mem[i][j] = -1e18;
        }
    }

    mem[1][0] = 0;

    // mask = bitstring show which city visit or not?
    // u = last place we stand
    // v = next place we will stand
    for (int mask=1; mask < (1<<n); mask++) {
        for (int u=0; u<n; u++) {
            // (mask & (1<<u)) checks if u in mask 
            // (mem[mask][u] != -1e18) if u is already visited, if it still be inf so it cant reach
            if ((mask & (1<<u)) && mem[mask][u] != -1e18) {
                // (u == n-1) if u is last city and (mask != (1<<n)-1) mask not in the last iteration
                if (u == n-1 && mask != (1<<n)-1) continue;

                for (int v=0; v<n; v++) {
                    // (!(mask & (1<<v))) check that v is not be visited yet
                    if (!(mask & (1<<v))) {
                        // next mask is next city will go to (future ite) so we update first
                        // (mask | (1<<v)) mark that bit to 1 and update its value
                        int next_mask = mask | (1<<v); 
                        mem[next_mask][v] = max( mem[next_mask][v] , mem[mask][u] + adj[u][v] );
                        cout << mask << " " << u << " " << v << endl;
                    }
                }

            }
        }
    }

    cout << mem[(1<<n)-1][n-1];

}