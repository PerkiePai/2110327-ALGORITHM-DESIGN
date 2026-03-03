#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> mem;

ll fib( ll n ) {
    if ( n <= 2 ) return mem[n] = 1;

    if ( mem[n] == -1 ) {
        mem[n] = fib(n-1) + fib(n-2);
        return mem[n];
    } else {
        return mem[n];
    }
}

int main() {
    ll n; cin >> n;
    mem.resize(n+1 , -1);
    cout << fib(n);
}