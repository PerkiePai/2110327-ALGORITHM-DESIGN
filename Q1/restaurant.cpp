#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int N, A; cin >> N >> A;
    vector<ll> v;
    ll mx = 0;
    while (N--) {
        ll t; cin >> t;
        v.push_back(t);
        mx = max(mx,t);
    }
    while (A--) {
        ll t; cin >> t;
        
        ll l, r;
        l = 0;
        r = mx * t;
        while (l<r) {
            ll mid = (l+r)/2;
            
            ll cnt = v.size();
            for (auto &x : v) {
                cnt += floor(mid/x);
            }
            if (cnt >= t) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        cout << l << endl;
    }
}