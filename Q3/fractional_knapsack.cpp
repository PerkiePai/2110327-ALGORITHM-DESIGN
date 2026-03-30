#include <bits/stdc++.h>
using namespace std; 

int main() {
    double w,n; cin >> w >> n;
    vector<double> v1(n), v2(n);
    vector<pair<double, pair<double, double>>> vp(n);

    for (int i = 0; i < n; i++) cin >> v1[i]; 
    for (int i = 0; i < n; i++) cin >> v2[i]; 
    
    for (int i = 0; i < n; i++) {
        double ratio = 0;
        if (v2[i] > 0) {
            ratio = v1[i] / v2[i];
        }
        vp[i] = {ratio, {v1[i], v2[i]}};
    }

    sort(vp.rbegin(), vp.rend());

    double sum = 0;
    double remainW = w;

    for (int i = 0; i < n; i++) {
        if (remainW <= 0) break;
        
        double ratio = vp[i].first;
        double itemW = vp[i].second.second;
        
        double take = min(itemW, remainW);
        sum += take * ratio;
        remainW -= take;
    }

    printf("%.4f", sum);

}