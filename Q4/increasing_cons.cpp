#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N; cin >> N;
    map<ll,ll> m;
    for(ll i=0; i<N; i++) {
        ll d; cin >> d;
        m[d]++;
    }

    vector<pair<ll,ll>> v;
    for (auto x : m) {
        if (x.second == 1) continue;
        v.push_back({x.second, x.first});
    }
    sort(v.begin(), v.end());
    ll cnt = 0;
    for (auto x: v) {
        cnt += x.first*x.first;
    }
    cout << cnt;

}