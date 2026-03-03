#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w; cin >> n >> w;
    vector<int> v(n+1); //vector of prefix sum
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        v[i] += v[i-1];
    }

    multiset<int> ms; //window of prefix sum length w
    ms.emplace(v[0]);
    int ans = -2e9;
    for (int i=1; i<=n; i++) {
        ans = max(ans, v[i]-*ms.begin());
        if (i-w>=0) ms.erase(v[i-w]);
        ms.emplace(v[i]);
    }
    cout << ans;
}