#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> mem;

ll bi(ll n, ll k) {
    if (k == 0 || n == k)
        return mem[n][k] = 1;

    if (mem[n][k] != -1)
        return mem[n][k];

    return mem[n][k] = bi(n-1,k-1) + bi(n-1,k);
}

int main() {
    ll n,k; cin >> n >> k;
    mem.assign(n+1 , vector<ll>(n+1, -1));
    cout << bi(n,k);
}