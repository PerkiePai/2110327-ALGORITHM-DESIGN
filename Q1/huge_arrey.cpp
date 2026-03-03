#include <iostream>
#include <map>

using namespace std;

int main() {
    int n,m; cin >> n >> m;
    map<int,int> mm ,ss;
    while (n--) {
        int d, t; cin >> d >> t;
        mm[d] += t;
    }

    int idx = 1;
    for (auto &x : mm) {
        ss[idx] = x.first;
        idx += x.second;
    }

    // for (auto &x : ss) {
    //     cout << x.first << " " <<  x.second << endl;
    // }
    while (m--) {
        int d; cin >> d;
        auto it = ss.upper_bound(d);
        it = prev(it);
        cout << it->second << "\n";
    }
}

