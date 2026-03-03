#include <bits/stdc++.h>
using namespace std;

pair<int,pair<int,int>> kanade(vector<int> v) {
    int minn = 0;
    int ans = INT_MIN;
    int l = 0; int r = 0; int temp = 0;
    vector<int> ps(v.size()+1);
    for (int i=1 ;i<=v.size() ; i++) {
        ps[i] += ps[i-1] + v[i-1];

        if (ps[i]-minn >= ans) {
            ans = ps[i]-minn;
            r = i;
            l = temp;
        }
        if (ps[i] <= minn) {
            minn = ps[i];
            temp = i;
        }
    }
    //cout << ans << " " << l << " " << r << "\n";
    return {ans,{l,r}};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> v(n);
    for (int i=0 ; i<n; i++) {
        cin >> v[i];
    }

    auto x = kanade(v);
    vector<int> a, b;
    for (int i=0; i<v.size() ; i++) {
        if (i<((x.second).first)) {
            a.push_back(v[i]);
        } else if (i>=((x.second).second)) {
            b.push_back(v[i]);
        } 
    }

    for (auto x: b) {
        cout << x << " ";
    }

    int twopart = INT_MIN;
    if (!a.empty() && !b.empty()) {
        twopart = x.first + max(kanade(a).first , kanade(b).first);
    } else if (!a.empty()) {
        twopart =  x.first + kanade(a).first;
    } else if (!b.empty()) {
        twopart =  x.first + kanade(b).first;
    } 
    
    cout << max(x.first , twopart);

}