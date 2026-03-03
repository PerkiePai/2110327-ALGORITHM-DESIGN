#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, w; cin >> n >> w;
    vector<int> v(n+1);
    for (int i=1 ; i<=n; i++) {
        cin >> v[i];
        v[i] += v[i-1];
    }

    deque<int> dq; dq.push_front(0); //store idx of vector of prefix
    int ans = -2e9;

    for (int i=1; i<=n; i++) {
        
        if (!dq.empty() && i-w > dq.front()) dq.pop_front(); //remove if extended width cons by 

        ans = max(ans, v[i]-v[dq.front()]);   
                                        // v-- remove if last in queue is greater than new prefix
        while (!dq.empty() && v[dq.back()] >= v[i]) dq.pop_back(); //remain mininum of prefix

        dq.push_back(i);
    }
    cout << ans;
}