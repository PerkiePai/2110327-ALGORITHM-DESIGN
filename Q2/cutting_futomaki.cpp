#include <bits/stdc++.h>
using namespace std;

vector<int> ss;
vector<vector<int>> mem;

int cf(int l, int r) {

    //cout << l << " " << r << "\n";

    if (r<=l || l<=0 || r<=0) return 0;
    if (mem[l][r] != -1) return mem[l][r];

    if ( r-l == 1 ) return max(ss[l] , ss[r]);

    int twoleft = cf(l+2,r) + max(ss[l],ss[l+1]);
    int tworight = cf(l,r-2) + max(ss[r],ss[r-1]);
    int leftright = cf(l+1,r-1) + max(ss[l],ss[r]);
    
    return mem[l][r] = max(leftright , max(twoleft , tworight));
}

int main() {
    int n; cin >> n;
    ss.resize(n+1);
    mem.resize(n+1 , vector<int>(n+1, -1));
    for (int i=1 ;i<=n; i++) {
        cin >> ss[i];
    }

    cout << cf(1,n);
}