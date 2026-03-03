#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
vector<pair<int,int>> v;

vector<int> recur(int l, int r) { //[l,r] 0 -> (n-1) return idx of frontier
    if (l==r) return {l};

    int mid = (l+r)/2;

    vector<int> a = recur(l,mid);
    vector<int> b = recur(mid+1,r);

    int maxY = -1;
    for (int x: b) {
        maxY = max(maxY, v[x].second);
    }

    vector<int> out; 
    for (int x: a) {
        if (v[x].second > maxY) {
            out.push_back(x);
        }
    }
    for (int x: b) {
        out.push_back(x);
    }

    return out;
}

int main() {
    int n; cin >> n;

    for (int i=0; i<n; i++) {
        int d, dd; cin >> d >> dd;
        v.push_back({d,dd});
    }
    sort(v.begin(),v.end());

    auto out = recur(0,n-1);
    cout << out.size();
}