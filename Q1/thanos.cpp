#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll p,k,a,b;
vector<ll> v;

ll recur(ll l, ll r) { //from [l,r] 
    auto it_l = lower_bound(v.begin(),v.end(),l);
    auto it_r = upper_bound(v.begin(),v.end(),r);

    ll out = 0;
    if (it_r - it_l == 0) {
        out = a;
        return out;
    } else {
        out = b*(it_r - it_l)*(r-l+1);
    }

    if (r == l) return out;

    ll mid = (l+r)/2;
    return min(out , recur(l,mid) + recur(mid+1,r));
}

int main() {
    cin >> p >> k >> a >> b;
    v.resize(k);
    for (ll i = 0 ; i<k ; i++) {
        ll d; cin >> d;
        v[i] = d;
    }
    sort(v.begin(),v.end());
    ll r = pow(2,p);
    cout << recur(1,r);

}