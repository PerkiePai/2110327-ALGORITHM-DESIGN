#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

void recur(int a, int b, int x, int y) {
    if (a == 0) {
        v[x][y] = b;
        return;
    }
    recur(a-1, b, 2*x, 2*y);
    recur(a-1, b-1, 2*x, 2*y+1);
    recur(a-1, b+1, 2*x+1, 2*y);
    recur(a-1, b, 2*x+1, 2*y+1);
    
}

int main() {
    int n,m; cin >> n >> m;

    int si = pow(2,n);
    v.resize(si);

    for (int i=0; i<si; i++) {
        vector<int> vv(si);
        v[i]=vv;
    }

    if (n==0) {
        cout << m;
        return 0;
    } else {
        recur(n,m,0,0);
    }
    
    for (auto x: v) {
        for (auto y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
}   