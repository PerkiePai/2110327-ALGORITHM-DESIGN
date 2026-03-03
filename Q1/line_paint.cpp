#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {
    int n; cin >> n;
    map<int,int> m;
    while (n--) {
        int l,r; cin >> l >> r;
        auto it = m.lower_bound(l);
        
        //merge left
        if (it != m.begin() && l <= prev(it)->second+1) {
            l = prev(it)->first;
            r = max(r, prev(it)->second); // dont forget to change r of prev
            it = m.erase(prev(it));
        }

        //merge right
        while (it != m.end()) {
            if (r >= it->first-1) {
                r = max(it->second , r);
                it = m.erase(it);
            } else {
                break;
            }
        }

        m[l] = r;
    }

    for (auto &x : m) {
        cout << x.first << " " << x.second << " ";
    }
}