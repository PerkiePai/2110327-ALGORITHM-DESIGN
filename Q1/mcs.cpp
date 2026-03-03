#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n+1);
    int ans = -2e9;
    int minn = 0;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        v[i] += v[i-1];
        ans = max(ans, v[i]-minn);
        minn = min(minn, v[i]);
    }
    cout << ans;
}