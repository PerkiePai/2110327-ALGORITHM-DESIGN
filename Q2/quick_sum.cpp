#include <bits/stdc++.h>
using namespace std;
using ll = long long;



// ll qs(vector<ll> &A) {
//     //Create a 2D array p which is used to store the value of P(a,b)
//     // p will be applicable for only non-negative value of a and b

    
// }

/*
00 01
10 11
*/

int main() {
    ll N, M, K; cin >> N >> M >> K; 
    vector<vector<ll>> A(N, vector<ll>(M)), p(N, vector<ll>(M));
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> A[i][j];
        }
    }

    p[0][0] = A[0][0];
    for (int j=1; j<M; j++) {
        p[0][j] = p[0][j-1] + A[0][j];
    }
    for (int i=1; i<N; i++) {
        p[i][0] = p[i-1][0] + A[i][0];
        for (int j=1; j<M; j++) {
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + A[i][j];
        }
    }
    // for (auto x: p) {
    //     for (auto y: x) {
    //         cout << y << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i=0; i<K; i++) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        int q1 = (r1-1>=0 && c1-1>=0) ? p[r1-1][c1-1] : 0;
        int q2 = (c1-1>=0) ? p[r2][c1-1] : 0;
        int q3 = (r1-1>=0) ? p[r1-1][c2] : 0;
        int q4 = p[r2][c2];
        cout << q4 - q3 - q2 + q1 << "\n";
    }
}