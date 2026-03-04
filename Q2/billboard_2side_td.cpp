#include <bits/stdc++.h>
using namespace std;

int n, w, k; 
vector<int> vl, vr;
vector<vector<int>>  meml, memr;

int bbr(int n, int k); 

int bbl(int n, int k) {
    if (n<=0 || k==0) return 0;
    if (meml[n][k] != -1) return meml[n][k];

    int gain = max(bbl(n-1, k) , bbr(n-w-1, k-1)+vl[n]);
    
    return meml[n][k] = gain;

} 

int bbr(int n, int k) {
    if (n<=0 || k==0) return 0;
    if (memr[n][k] != -1) return memr[n][k];

    int gain = max(bbr(n-1, k) , bbl(n-w-1, k-1)+vr[n]);

    return memr[n][k] = gain;
} 

int main() {
    cin >> n >> w >> k;
    vl.resize(n+1); vr.resize(n+1); 
    meml.resize(n+1, vector<int>(n+1, -1)); memr.resize(n+1, vector<int>(n+1, -1)); 
    for (int i=1; i<=n; i++) {
        cin >> vl[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> vr[i];
    }

    int gain = max(bbl(n,k) , bbr(n,k));
    cout << gain;
}