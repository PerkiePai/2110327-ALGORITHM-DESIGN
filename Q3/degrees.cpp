#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> mem(n,vector<int>(n, -1));
    map<int,int> m;
    int maxx = -2e9;
    for (int i=0 ;i<n; i++) {
        int cnt = 0;
        for (int j=0;j<n; j++) {
            cin >> mem[i][j];
            cnt += mem[i][j];
        }
        m[cnt] += 1;
        maxx = max(cnt , maxx);
    }
    for (int i=0; i<=maxx; i++) {
        if (m.count(i)) {
            cout << m[i] << " ";
        } else {
            cout << 0 << " ";
        }
    }

}