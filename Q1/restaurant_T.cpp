#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, A;
    cin >> N >> A;

    priority_queue< pair<ll,int> , vector<pair<ll,int>> , greater<> > pq;

    int NN = N;
    while (NN--) {
        int cntt; cin >> cntt;
        pq.push(make_pair(0,cntt));
    }

    vector<int> v(100000), vv;
    int AA = A;
    while (AA--) {
        ll t; cin >> t;
        vv.push_back(t);
    }


    ll pi = 1;
    for (auto &x : vv) {
        while (pi<x) {
            auto xx = pq.top(); pq.pop();
            pq.push(make_pair(xx.first+xx.second , xx.second));
            pi++;
        }
        auto xx = pq.top();
        v[pi]=xx.first+xx.second;
    }

    for (auto &x : vv) {
        cout << v[x] << endl;
    }
}
