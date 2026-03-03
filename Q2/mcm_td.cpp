#include <bits/stdc++.h>
using namespace std;

vector<int> p = {5,4,10,2,20};
int n = p.size() - 1;

int solve(int i, int j, vector<vector<int>> &mem) {
    if (i==j) return mem[i][j] = 0;

    if (mem[i][j] != -1) return mem[i][j];

    int minn = INT_MAX;
    for (int k = i; k<j ;k++) {
        int cost = solve(i, k, mem) + solve(k+1, j, mem) + (p[i-1] * p[k] * p[j]);
        minn = min(minn , cost);
    }

    return mem[i][j] = minn;
}

int main() {
    
    

    vector<vector<int>> mem(n+1 , vector<int>(n+1 , -1));

    cout << solve(1,n,mem);

    cout << "\n";
    for (auto x : mem) {
        for (auto y : x) {
            cout << y << "\t";
        }
        cout << "\n";
    }
}