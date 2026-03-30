#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

ll MOD = 1000000007;
int n,k;
vector<vector<ll>> mem;
vector<ll> a;

ll gt(ll len, ll cur_i) {
    if (len > n) return 0;
    if (len == n) return 1;

    if (mem[len][cur_i] != -1) return mem[len][cur_i];

    ll gain = 0;
    if (cur_i == 1) {
        gain += gt(len+1, 1);
        gain += gt(len+2, 2);
    } else if (cur_i == 2) {
        gain += gt(len+1, 1);
        gain += gt(len+4, 4);
    } else {
        gain += gt(len+2, 2);
        gain += gt(len+4, 4);
    }

    return mem[len][cur_i] = gain%MOD;
}



int main() {
    cin >> n >> k;
    ll siz = min(n,10000);
    mem.resize(siz+1, vector<ll>(siz+1, -1));
    a.resize(k+1);
    for (int i=1; i<=k; i++) {
        cin >> a[i];
    }
    
    ll gain = 0;
    gain += gt(1, 1);
    gain += gt(2, 2);
    gain += gt(4, 4);
    cout << gain%MOD;
}