#include <bits/stdc++.h>
using namespace std;

int dr[] = {-2,-2,-1,-1,1,1,2,2};
int dc[] = {-1,1,-2,2,-2,2,-1,1};

int N;
bool board[15][15];  // Track knight placements
long long total_sol = 0;

// Check if placing a knight at (r, c) is safe
bool isSafe(int r, int c) {
    // Check all knight move positions - if any has a knight, it's unsafe
    for (int i = 0; i < 8; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
            if (board[nr][nc]) {
                return false;  // Knight found at attacking position
            }
        }
    }
    return true;
}

// Backtracking to place knights row by row
void solve(int row) {
    if (row == N) {
        total_sol++;
        return;
    }
    
    // Try placing a knight in each column of current row
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = true;
            solve(row + 1);
            board[row][col] = false;  // Backtrack
        }
    }
}

int main() {
    cin >> N;
    
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    solve   (0);
    
    cout << total_sol << endl;
    
    return 0;
}