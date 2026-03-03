#include <bits/stdc++.h>
using namespace std;



int main() {
    int n,m; cin >> n >> m;
    vector<int> v;
    while (n--) {
        int d; cin >> d;
        v.push_back(d);
    }
    while (m--) {
        int d; cin >> d;
        
        int l = 0;
        int r = v.size();
        while (r>l) {
            if ((r-l) <= 1) break;

            int mid = (l+r) /2;
            if (v[mid] <= d) {
                l = mid;
            } else {
                r = mid;
            }
        }

        cout << ((d < v[l] ) ?  -1 :  v[l] )<< endl;

    }
}