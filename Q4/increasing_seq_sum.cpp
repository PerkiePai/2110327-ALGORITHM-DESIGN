#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<ll> mem(N+1, 0);

    mem[0] = 1;

    for (int i=1; i<=N; i++) {
        for (int j=i; j<=N; j++) {
            mem[j] += mem[j-i];
        }
    }

    cout << mem[N];
}