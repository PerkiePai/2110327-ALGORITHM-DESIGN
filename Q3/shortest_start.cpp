#include <bits/stdc++.h>
using namespace std;

/*
    bellman ford table EDGE ~10^5

    it is 2d arrey that will choose shorter path between that cell with n length  and new path with n+1 length 
    loop till find 

*/

int main() {
    int n,m,k,v; cin >> n >> m >> k >> v;

    vector<int> init(k);
    for (int i=0 ;i<k ;i++) {
        cin >> init[i];
    }

    vector<int> ea(m), eb(m), w(m);
    for (int i=0; i<m; i++) {
        cin >> eb[i] >> ea[i] >> w[i];
    }

    vector<int> dist(n, INT_MAX/4), prev(n, -1); // dist init is all MAX 
    dist[v] = 0; //dist at end is 0

    cout << "ite " << 0  << ": " ;
    for (auto x: dist) {
        cout << x << " ";
    } cout << "\n";

    for (int i=1; i<n; i++) { // fill and update the 2d table 
        for (int j=0; j<m; j++) { // choose which path is better  
            if (dist[ea[j]] + w[j] < dist[eb[j]]) { // check if 
                dist[eb[j]] = dist[ea[j]] + w[j];
            }
        }
        cout << "ite " << i  << ": " ;
        for (auto x: dist) {
            cout << x << " ";
        } cout << "\n";
    }

    int minn = INT_MAX;
    for (int i=0 ;i<k ;i++) {
        minn = min(minn, dist[init[i]]);
    }

    cout << minn;
 
}