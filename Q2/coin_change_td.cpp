#include <bits/stdc++.h>
using namespace std;

vector<int> c, mem;

int cc(int n) {
    
    if (n==0) return 0;
    if (mem[n] != -1) return mem[n];
    
    
    int cnt = INT_MAX;
    for (auto x: c) {
        if (n-x < 0) continue;
        cnt = min(cnt , cc(n-x)+1);
    }

    //cout << cnt << "\n";
    return mem[n] = cnt;
}

int main() {
    int n,m; cin >> n >> m;
    c.resize(n); mem.resize(m+1, -1);
    for (int i=0; i<n; i++) cin >> c[i];

    cout << cc(m);

    // for (auto x: mem) {
    //     cout << x << " ";
    // }

}