#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;

vector<int> recur(int l, int r) {
    if (l==r) return {l};

    int mid = (l+r)/2;

    vector<int> a = recur(l,mid);
    vector<int> b = recur(mid+1,r);

    int maxY = -1;
    for (auto x: b) {
        maxY = max(maxY, v[x].second);
    }

    vector<int> out;
    for (auto x: a) {
        if (v[x].second > maxY) out.push_back(x);
    }

    for (auto x: b) out.push_back(x);

    return out;
    
}

int main() {
    int n; cin >> n;
    v.resize(n);
    for (int i=0 ;i<n ;i++) {
        int a,b; cin >> a >> b;
        v[i] = {a,b};
    }
    sort(v.begin(), v.end());

    cout << recur(0,n-1).size();
}