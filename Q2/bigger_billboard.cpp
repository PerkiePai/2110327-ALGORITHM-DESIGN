#include <bits/stdc++.h>
using namespace std;

vector<int> mem ,c;

int bb(int n) {
    if (n<=0) return 0;
    if (mem[n] != -1) return mem[n];

    int gain = max(bb(n-3)+c[n], bb(n-1));
    
    return mem[n] = gain;
}

int main() {
    int n; cin >> n;
    c.resize(n+1);
    mem.resize(n+1 , -1);
    for (int i=1; i<=n; i++) {
        cin >> c[i];
    }
    cout << bb(n);
}