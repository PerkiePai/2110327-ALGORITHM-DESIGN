#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N,M,K,W; cin >> N >> M >> K >> W;
    vector<int> m(M+1);
    for (int i=1; i<=M; i++) {
        cin >> m[i];
    }
    ll total_health = 0;
    vector<int> h(M+1);
    for (int i=1; i<=M; i++) {
        cin >> h[i];
        total_health += h[i];
    }
    //vector<pair<int,int>> p(M);
    map<int,int> mem;
    for (int i=1; i<=M; i++) {
        //p[i-1] = {m[i], h[i]};
        mem[m[i]] += h[i];
    }
    //sort(p.begin(), p.end());
    vector<pair<int,int>> p;
    for (auto x: mem) {
        p.push_back({x.first , x.second});
    }
    

    int idx = 0; //idx in vector pair 
    int place = max(1, p[0].first-W); //where to tower
    int remain_mons = m.size();
    int remain_tow = K;
    int total_dmg = 0;
    while (true) {
        if (place > N) {break;}
        if (remain_mons == 0) {break;}
        if (remain_tow == 0) {break;}

        remain_tow--;
        total_dmg++;
        cout << idx << " "  << place << " " << p[idx].second-1 << endl;

        p[idx].second--;
        place++;

        if (p[idx].second == 0 || place > p[idx].first+W) {
            idx++;
            if (idx == p.size()) break;
            place = max(place, p[idx].first-W);
            remain_mons--;
            continue;
        }

    }
    cout << total_health - total_dmg << endl;


}