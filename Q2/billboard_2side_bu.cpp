#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w, k; cin >> n >> w >> k;
    vector<int> vl(n+1), vr(n+1);
    vector<vector<int>>  meml(n+1 , vector<int>(k+1)), memr(n+1 , vector<int>(k+1));

    for (int i=1; i<=n; i++) {
        cin >> vl[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> vr[i];
    }

    for (int in=1 ; in<=n; in++) {
        for (int jk=1; jk<=k; jk++) {
            meml[in][jk] = meml[in-1][jk];
            memr[in][jk] = memr[in-1][jk];

            int idx = max(0, in - w - 1);

            meml[in][jk] = max(meml[in][jk] , memr[idx][jk-1] + vl[in]);
            memr[in][jk] = max(memr[in][jk] , meml[idx][jk-1] + vr[in]);

        }
    }

    int maxx = INT_MIN;
    for (int i=1 ; i<=k; i++) {
        maxx = max({maxx, meml[n][i], memr[n][i]});
    }
    cout << maxx;
    
}