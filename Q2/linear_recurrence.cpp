#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll k, nn;
vector<ll> c ,a;
ll MOD = 32717;
vector<ll> mem;

ll lr(ll n) {
    if (n<k) return a[n];
    ll val = 0;
    for (int i=1; i<=k; i++) {
        if (mem[n-i] == -1) {
            mem[n-i] = lr(n-i);
        }
        val += ((c[i]%MOD)*(mem[n-i]%MOD))%MOD;
    }
    return val%MOD;
}   

int main() {
    cin >> k >> nn;
    mem.resize(nn+1 , -1);
    c.resize(k+1); a.resize(k+1);
    for (int i=1; i<=k; i++) {
        cin >> c[i];
    } 
    for (int i=0; i<k; i++) {
        cin >> a[i];
    }
    cout << lr(nn);
}