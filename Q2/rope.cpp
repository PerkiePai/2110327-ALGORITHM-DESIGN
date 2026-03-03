#include <bits/stdc++.h>
using namespace std;

vector<int> len(3), mem;

int rp(int n) {
    if (n<0) return -INT_MAX;
    if (n==0) return 0;
    if (mem[n] != -1) return mem[n];


    int parts = max(rp(n-len[0])+1 , max(rp(n-len[1])+1 ,rp(n-len[2])+1));

    return mem[n] = parts;
}

int main() {
    int n; cin >> n >> len[0] >> len[1] >> len[2];
    mem.resize(n+1 , -1);
    cout << rp(n);
}