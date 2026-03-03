#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n+1);
    int ans = -2e9;
    int minn = 0;

    int minos = 2e9;
    int maxx = 0;

    for (int i=1; i<=n ; i++) {
        cin >> v[i];
        v[i] += v[i-1];

        ans = max(ans, v[i]-minn);
        minn = min(minn, v[i]);

        minos = min(minos, v[i]-maxx);
        maxx = max(maxx, v[i]);
    }
    if (ans >= 0) {
        cout << max(ans, v[n]-minos);
    } else {
        cout << ans;
    }

    

}