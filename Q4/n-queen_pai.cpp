#include <bits/stdc++.h>
using namespace std;

vector<bool> valid_col(15);
vector<bool> valid_diag1(30), valid_diag2(30);
int total;
int N; 

void isValid(int r) {
    if (r == N) {
        total++;
        return;
    }

    for (int c=0; c<N; c++) {
        int d1 = r+c;
        int d2 = r-c+N;

        if (valid_col[c] || valid_diag1[d1] || valid_diag2[d2]) continue;

        valid_col[c] = true;
        valid_diag1[d1] = true;
        valid_diag2[d2] = true;

        isValid(r+1);

        valid_col[c] = false;
        valid_diag1[d1] = false;
        valid_diag2[d2] = false;
        
    }
}

int main() {
    cin >> N;
    total = 0;
    isValid(0);
    cout << total;
}