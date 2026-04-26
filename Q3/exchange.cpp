#include <bits/stdc++.h>
using namespace std; 

//double mem[502][502];
vector<vector<double>> mem;

int main() {
    int K; cin >> K;
    
    for (int iii=1; iii<=K; iii++) {

        int N; cin >> N;
        mem.assign(N+1, vector<double>(N+1,-1));
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                cin >> mem[i][j];
            }
        }
        
        bool check = true;
        for (int k=1; k<=N; k++) {
            for (int i=1; i<=N; i++) {
                for (int j=1; j<=N; j++) {
                    mem[i][j] = max(mem[i][j] , mem[i][k] * mem[k][j]);
                }
            }
        }
        for (int i=1; i<=N; i++) {
            if (mem[i][i] != 1) {
                check = false;
                break;
            }
        }
        cout << ( (check) ? "NO\n" : "YES\n" );

    }

    
    
    
}