#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<vector<vector<vector<int>>>> mem;

int bc(int len, int cur_m, int cur_k, int is_black) {
    if (cur_m > m || cur_k > k) return 0;
    if (mem[len][cur_m][cur_k][is_black] != -1) return mem[len][cur_m][cur_k][is_black];

    if (len == n) return (cur_k == k) ? 1 : 0;

    if (cur_m == m && cur_k == k) return bc(len+1, 1, cur_k+1, !is_black);

    return mem[len][cur_m][cur_k][is_black] = bc(len+1 , cur_m+1, cur_k, is_black) + bc(len+1 , 1, cur_k+1, !is_black);
}

int main() {
    cin >> n >> m >> k; 
    mem.resize(n+1 , vector<vector<vector<int>>>(m+1, vector<vector<int>>(k+1, vector<int>(2, -1))));
    cout << bc(1, 1, 0, 1);
}