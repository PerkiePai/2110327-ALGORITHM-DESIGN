#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<int,priority_queue<int, vector<int>, greater<int>>> m;
    vector<int> v(n+1);

    int sum = -2e9;
    for (int i=1; i<=n; i++) {
        int d; cin >> d;
        v[i]=d+v[i-1];
        
        m[d].push(v[i-1]);
        sum = max(sum, v[i]-m[d].top());
        
    }
    
    cout << sum;

}