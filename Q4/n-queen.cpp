#include <bits/stdc++.h>
using namespace std;


int total_sol = 0;
bool col_check[15]; // 0-N
bool diag1_check[30]; // "/"
bool diag2_check[30]; // "\"

void solve(int row , int N) {
    if (row == N) {
        total_sol++;
        return;
    }

    for (int c=0; c<N; c++) {
        int d1 = row+c;
        int d2 = row-c +N;

        if ( !col_check[c] && !diag1_check[d1] && !diag2_check[d2] ) {
            col_check[c] = true;
            diag1_check[d1] = true;
            diag2_check[d2] = true;
            
            solve(row+1 , N);

            col_check[c] = false;
            diag1_check[d1] = false;
            diag2_check[d2] = false;

        } 
    }

}

int main() {
    int N; cin >> N;

    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    solve(0,N);

    cout << total_sol;

}