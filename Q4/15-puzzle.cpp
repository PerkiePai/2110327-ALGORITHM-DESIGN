#include <bits/stdc++.h>
using namespace std;

struct Board {
    int grid[4][4];
    int emptyRow, emptyCol;
};

int targetPos[16][2]; // const array store the place to their home // i = that number tile // j when 0=rol 1=col

int getManhattan(const Board& b) { //return every tile val to their home
    int distance = 0;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            int val = b.grid[i][j];
            if (val != 0) { 
                // calculate the distance to move between that val to his home
                distance += abs(i-targetPos[val][0]) + abs(j-targetPos[val][1]);
            }
        }
    }
    return distance;
}

int dx[] = {-1,1,0,0}; // i = 0/1/2/3 moves = up/down/left/right
int dy[] = {0,0,-1,1};
int minThreshold; //smallest moves that invalid (exceed limit)
bool solved;

// g = moves made since the start 
// threshold = max allow total moves
// prevMove = last move, to prevent death loop
void dfs(Board &b, int g ,int threshold, int prevMove) {
    int h = getManhattan(b);
    int f = g+h; // estimate total move will use

    if (f > threshold) {
        minThreshold = min(minThreshold , f);
        return; 
    }

    if (h==0) {
        solved = true;
        return;
    }

    for (int i=0; i<4; i++) {
        if ( prevMove == 0 && i == 1 ) continue;
        if ( prevMove == 1 && i == 0 ) continue;
        if ( prevMove == 2 && i == 3 ) continue;
        if ( prevMove == 3 && i == 2 ) continue;

        int nr = b.emptyRow + dx[i];
        int nc = b.emptyCol + dy[i];

        if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue;
        
        int oldR = b.emptyRow; 
        int oldC = b.emptyCol; 

        swap( b.grid[nr][nc] , b.grid[oldR][oldC] ); //swap tile number val

        // store emptyRow and emptyCol to backtrack
        b.emptyRow = nr;
        b.emptyCol = nc;

        dfs(b, g+1, threshold, i);
        if (solved) return;

        b.emptyRow = oldR;
        b.emptyCol = oldC;
        swap( b.grid[nr][nc] , b.grid[oldR][oldC] ); //swap tile number val

    }

}

int main() {

    Board start;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cin >> start.grid[i][j];
            if (start.grid[i][j] == 0) {
                start.emptyRow = i;
                start.emptyCol = j;
            }
        }
    }

    // init targetpos to their home by targetPos[i][j]
    // i = that number tile // j when 0=rol 1=col
    for (int i=0; i<15; i++) { 
        targetPos[i+1][0] = i/4;
        targetPos[i+1][1] = i%4;
    }
    // tile number 0 belong to rol/col = 3/3
    targetPos[0][0] = 3; 
    targetPos[0][1] = 3;

    int threshold = getManhattan(start); 
    solved = false;

    while (!solved) {
        minThreshold = INT_MAX;
        dfs(start, 0, threshold, -1);
        if (solved) {
            cout << threshold << endl;
            break;
        }
        threshold = minThreshold;
    }

}