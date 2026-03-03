#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<pair<int,int>> v(N);
    for (int i=0; i<N; i++) {
        int a,b; cin >>a >> b;
        v[i]={a,b};
    }
    sort(v.begin(),v.end());

    int maxY = -1;
    int cnt = 0;
    for (int i=N-1; i>=0; i--) {
        int y = v[i].second;
        if (y > maxY) {
            cnt++;
            maxY = y;
        }
    }
    cout << cnt;

}