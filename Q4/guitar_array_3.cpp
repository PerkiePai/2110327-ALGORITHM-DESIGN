#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> grid;
struct Point { int r, c; };
vector<Point> targets;
bitset<144> precomputed[12][12];
vector<Point> coverage_list[144]; // coverage_list[i] = list of (r,c) that cover targets[i]

bool solve(int k, bitset<144> currentCover, vector<Point>& result) {
    // If all targets covered, we are done
    if (currentCover.count() == targets.size()) return true;
    // If no more transmitters allowed, fail
    if (k <= 0) return false;

    // 1. Find the target cell that is hardest to cover (fewest options)
    int best_target = -1;
    int min_options = 1e9;

    for (int i = 0; i < targets.size(); ++i) {
        if (!currentCover.test(i)) {
            int options = 0;
            for (auto& p : coverage_list[i]) options++;
            if (options < min_options) {
                min_options = options;
                best_target = i;
            }
        }
    }

    if (best_target == -1) return false;

    // 2. Branch only on the positions that can cover this specific "hard" target
    for (auto& pos : coverage_list[best_target]) {
        result.push_back(pos);
        if (solve(k - 1, currentCover | precomputed[pos.r][pos.c], result)) return true;
        result.pop_back();
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> M)) return 0;
    grid.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == '.') targets.push_back({i, j});
        }
    }

    if (targets.empty()) {
        for (auto& row : grid) cout << row << "\n";
        return 0;
    }

    // Precompute which targets each (r, c) covers
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            bitset<144> m;
            for (int i = 0; i < targets.size(); ++i) {
                int tr = targets[i].r, tc = targets[i].c;
                bool covers = (r == tr || c == tc || abs(r - tr) == abs(c - tc) || 
                              (abs(r - tr) == 1 && abs(c - tc) == 2) || 
                              (abs(r - tr) == 2 && abs(c - tc) == 1));
                if (covers) {
                    m.set(i);
                    coverage_list[i].push_back({r, c});
                }
            }
            precomputed[r][c] = m;
        }
    }

    // IDDFS: Start from 1 transmitter up to N*M
    for (int k = 1; k <= (int)targets.size(); ++k) {
        vector<Point> result;
        if (solve(k, bitset<144>(0), result)) {
            for (auto& p : result) grid[p.r][p.c] = 'X';
            break;
        }
    }

    for (int i = 0; i < N; ++i) cout << grid[i] << "\n";

    return 0;
}