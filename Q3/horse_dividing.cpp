#include <bits/stdc++.h>
using namespace std; 

int n;
vector<int> h;
int found = 0;

void re(int idx, int spc, int ril ,vector<int> vs, int idx_min_vs) {

    if (found) return;

    // for (auto x: vs ) {
    //     cout << x <<" ";
    // } cout << spc << " " <<ril <<  "\n";
    //cout << idx << "\n";

    if (idx == 0) {
        //check if valid
        if (spc > ril && spc - h[idx_min_vs] <= ril + h[idx_min_vs]) {
            cout << vs.size() << "\n";
            for (auto x: vs) {
                cout << x << " ";
            }
            found = 1;
        }
        return;
    }
    auto temp = vs;
    
    //spc not take
    re(idx-1, spc, ril+h[idx], temp, idx_min_vs);

    //spc take
    if (h[idx] < h[idx_min_vs]) {
        idx_min_vs = idx;
    }
    temp.push_back(idx);
    re(idx-1, spc+h[idx], ril, temp, idx_min_vs);
    
}

int main() {
    cin >> n;
    h.resize(n+1, INT_MAX);
    for (int i=1; i<=n ;i++) {
        cin >> h[i];
    }

    re(n, 0, 0, {}, 0);


}