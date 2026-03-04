#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, C; cin >> R >> C; 
    vector<vector<int>> a(R+1, vector<int>(C+1, -1)), mem(R+1, vector<int>(C+1, 0));
    int maxx = 0;
    for (int i=1; i<=R; i++) {
        string d; cin >> d;
        for (int j=1; j<=C; j++) {
            a[i][j] = d[j-1] - '0';
            if (a[i][j] == 0) {
                mem[i][j] = 0;
            } else {
                mem[i][j] = min({mem[i-1][j], mem[i][j-1], mem[i-1][j-1]}) + 1;
                maxx = max(maxx , mem[i][j]);
            }
        }
    }

    // for (auto x: a) {
    //     for (auto y: x) {
    //         cout << y << " ";

    //     } cout << "\n";
    // }
    cout << maxx;
}