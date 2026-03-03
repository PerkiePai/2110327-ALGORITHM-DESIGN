#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    vector<int> s(n+1);
    for (int i=0; i<=n; i++) {
        cin >> s[i];
    }

    vector<vector<int>> dp(n+1 , vector<int>(n+1,0));
    for (int L=1; L<n; L++) { //L = how much we multiply
        for (int i=1; i<=n-L; i++) {
            int j = i+L;

            dp[i][j] = INT_MAX;
            for (int k=i; k<i+L; k++) {
                int cost = dp[i][k] + dp[k+1][j] + (s[i-1] * s[k] * s[j]);
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }

        }
    }

    cout << dp[1][n];

}