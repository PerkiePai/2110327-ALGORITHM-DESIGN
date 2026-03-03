#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll nn,k;
int MOD = 32717;

ll mr(ll n, vector<ll> &a, vector<vector<ll>> &b, vector<ll> &mem) {
    if ( n<=0 ) return 0;
    if ( n<=k ) return a[n] % MOD;
    if (mem[n] != -1) return mem[n];

    ll out = 0;
    for (int x: b[n]) {
        int idx = n - x;
        out = (out + mr(idx, a, b, mem)) % MOD;
    }
    return mem[n] = out%MOD;
}

int main() {
    cin >> nn >> k;
    vector<ll> a(k+1);
    vector<vector<ll>> b(nn+1);
    vector<ll> mem(nn+1, -1);

    for (int i=1; i<=k; i++) {
        cin >> a[i];
    }

    for (int i=k+1; i<=nn; i++) {
        int p; cin >> p;
        for (int j=1; j<=p; j++) {
            int d; cin >> d;
            b[i].push_back(d);
        }
    }

    for (int i=1; i<=nn; i++) {
        cout << mr(i, a, b, mem) << " ";
    }

}