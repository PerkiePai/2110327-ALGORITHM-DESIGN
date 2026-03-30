#include <bits/stdc++.h>
using namespace std; 

int main() {
    int n; cin >> n;
    vector<int> v1(n), v2(n);
    vector<pair<int,int>> vp(n);
    for (int i=0; i<n; i++) cin >> v1[i];
    for (int i=0; i<n; i++) cin >> v2[i];
    for (int i=0; i<n; i++) vp[i] = make_pair(v2[i],v1[i]);

    sort(vp.begin(), vp.end());

    int cnt = 1;
    int sec = vp[0].first;
    for (int i=1; i<n; i++) {
        if (vp[i].second >= sec) {
            cnt++;
            sec = vp[i].first ;
        }
    }

    cout << cnt;

}