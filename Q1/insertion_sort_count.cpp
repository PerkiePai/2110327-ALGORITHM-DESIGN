#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, m; cin >> n >> m;
    vector<int> v;
    while (n--) {
        int d; cin >> d;
        v.push_back(d);
    }
    while (m--) {
        int t; cin >> t;
        auto it = v.begin();
        int cnt = 0;
        while (it != v.end()) {
            if (t == *it) break;
            if (t < *it) {
                cnt++;
            }
            it++;
        }
        cout << cnt << endl;
    }
}