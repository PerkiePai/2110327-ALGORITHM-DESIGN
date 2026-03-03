#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W; cin >> n >> W;

    vector<int> v(n+1) , w(n+1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> w[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(W+1 , 0));
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=W; j++) {
            cin >> dp[i][j];
        }
    }

    int jj = W;
    vector<int> sol;
    for (int ii = n; ii>0; ii--) {
        if (dp[ii][jj] != dp[ii-1][jj]) {
            //cout << ii << " " << jj << "\n";
            sol.push_back(ii);
            jj = jj - w[ii];
        } 
    }
    cout << sol.size() << "\n";
    for (auto x: sol) {
        cout << x << " ";
    }

}