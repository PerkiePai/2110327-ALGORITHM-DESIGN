#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> v(n+1);
    for(ll i = 1; i <= n;i++){
        ll x;
        cin >> x;
        v[i] = x;
        v[i] += v[i-1];
    }
    while(m--){
        ll a,b;
        cin >> a >> b;
        ll f = a;
        ll l = n;
        while(f < l){
            cout << f << "->" << l << endl;
            ll mid = (f+l)/2;
            ll sum = v[mid]-v[a]+(mid-a+1)*k;
            if(sum <= b){
                f = mid+1;
            }
            else{
                l = mid;
            }
        }

        cout << v[f]-v[a] << endl;
    }
    
}