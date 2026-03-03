#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> dia((n*2),vector<int>(n+1 ,0)); //idx 1->7 //store prefix sum
    vector<int> vidx(n*2 , 1); //store backward of idx of each dia
    vector<int> vmin(n*2 , 0);
    vector<int> vans(n*2 , -INT_MAX);
    int maxx = -INT_MAX;

    for (int i=n; i>0; i--) {
        for (int j=i; j<i+n; j++) {
            int d; cin >> d;
            dia[j][vidx[j]] = d + dia[j][vidx[j]-1];
            
            vans[j] = max(vans[j] , dia[j][vidx[j]] - vmin[j]);
            vmin[j] = min(vmin[j] , dia[j][vidx[j]]);

            maxx = max(maxx , vans[j]);

            vidx[j]++;
        }
    }

    // for (auto x: dia) {
    //     for (auto y: x) {
    //         cout << y << "\t";
    //     }
    //     cout << "\n";
    // }
    
    cout << maxx;
}