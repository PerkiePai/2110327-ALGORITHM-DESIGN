#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k; 

int bs(int len, int cur_k) { //cur_k is len from last 1's
    if (len == n) return 1;

    if (cur_k <= k) return bs(len+1 , cur_k+1);

    return bs(len+1, 0) + bs(len+1, cur_k+1); 
}

int main() {
    cin >> n >> k;
    cout << bs(1,1) + bs(1,0);

}