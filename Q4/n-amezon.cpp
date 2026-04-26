#include <bits/stdc++.h>
using namespace std;

class AmazonSolver {
    int n;
    vector<int> board; // board[r] = c means Amazon at (r, c)
    int solutions = 0;

    bool isSafe(int row, int col) {
        for (int prevRow = 0; prevRow < row; ++prevRow) {
            int prevCol = board[prevRow];

            // 1. Queen constraints: Column and Diagonals
            if (prevCol == col || abs(prevCol - col) == abs(prevRow - row)) {
                return false;
            }

            // 2. Knight constraints: "L" shapes
            int rowDiff = abs(row - prevRow);
            int colDiff = abs(col - prevCol);
            if ((rowDiff == 1 && colDiff == 2) || (rowDiff == 2 && colDiff == 1)) {
                return false;
            }
        }
        return true;
    }

    void solve(int row) {
        if (row == n) {
            solutions++;
            printBoard();
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isSafe(row, col)) {
                board[row] = col;
                solve(row + 1);
                // Backtrack implicit by overwriting board[row] in next loop
            }
        }
    }

    void printBoard() {
        if (solutions > 1) return; // Only print the first solution found
        cout << "Solution found for N=" << n << ":" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << (board[i] == j ? " A " : " . ");
            }
            cout << endl;
        }
        cout << "-----------------------" << endl;
    }

public:
    AmazonSolver(int size) : n(size), board(size) {}
    void findSolutions() {
        solve(0);
        if (solutions == 0) cout << "No solutions exist for N=" << n << endl;
        else cout << "Total solutions: " << solutions << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cout << "Enter board size (N): ";
    if (!(cin >> n)) return 0;

    AmazonSolver solver(n);
    solver.findSolutions();

    return 0;
}