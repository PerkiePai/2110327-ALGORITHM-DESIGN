#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;

    vector<ll> v(n), a, b;
    ll maxx = 0;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        maxx = max(maxx, v[i]);
    }

    a.push_back(0);     a.push_back(1); 
    b.push_back(0);     b.push_back(1); 

    ll k = 1;
    while (b[k] < maxx) {
        k++;
        a.push_back(0);     b.push_back(0); 

        int idx = k - a[a[k-1]];
        a[k] = 1+a[idx];

        b[k] = b[k-1] + a[k];

    }

    for (auto x: v) {
        int ans = lower_bound(b.begin()+1, b.end(), x) - b.begin();
        cout << ans << "\n";
    }

    

}