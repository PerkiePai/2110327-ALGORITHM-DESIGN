#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m; cin >> n >> m;
    vector<int> c, mem;
    c.resize(n); mem.resize(m+1, 0);
    for (int i=0; i<n; i++) cin >> c[i];

    for (int i=1; i<=m; i++) {
        int cnt = INT_MAX;
        for (auto x: c) {
            if (i-x < 0) continue;
            cnt = min(cnt, mem[i-x]+1);
        }
        mem[i] = (cnt == INT_MAX) ? 0: cnt;
    }

    // for (auto x: mem) {
    //     cout << x << " ";
    // }

    cout << mem[m];
}