#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    ll N,Q;
    cin >> N >> Q;
    map<int,int> xc,ad_xc;
    while(N--){
        int x,c;
        cin >> x >> c;
        xc[x] += c;
    }
    auto it = xc.begin();
    ad_xc[it->second] = it->first;
    it++;
    auto nit = ad_xc.begin();
    for(it;it!=xc.end();it++){
        ad_xc[(it->second)+nit->first] = it->first;
        nit++;
    }
    // cout << ad_xc.size();
    // for (auto &x : ad_xc) {
    //     cout << x.first << " " <<  x.second << endl;
    // }

    while(Q--){
        int p;
        cin >> p;
        auto fit = ad_xc.lower_bound(p);
        cout << fit->second << endl;
    }
}