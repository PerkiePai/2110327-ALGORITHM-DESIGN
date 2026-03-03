#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n,m,k;
vector<ll> v;

ll bs(int a, int b) {

    ll start = v[a];
    ll l = a;
    ll r = n+1;

    ll cal = 0;
    while (r>l) {
        //cout << l << r << endl;
        if (r-l<=1) break;

        ll mid = (l+r)/2;

        cal = (v[mid]-start) + (mid-a)*k;
        if ( cal <= b ) {
            l = mid;
        } else {
            r = mid;
        }

    }

    return (v[l]-start);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m >> k;
    v.resize(n+1);

    for (int i=1; i<=n; i++) {
        cin >> v[i];
        v[i] += v[i-1];
    } 

    for (int i=0; i<m; i++) {
        ll a,b; cin >> a >> b;
        cout << bs(a,b) << "\n";
    }

}