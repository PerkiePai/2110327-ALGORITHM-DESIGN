#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> v(n);
    for (int i = 0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll sum=0;
    for (int i=1; i<n; i++) {
        sum+= (v[i-1]*v[i]);
    }

    cout << sum;
}