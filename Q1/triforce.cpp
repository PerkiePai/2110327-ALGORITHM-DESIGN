#include <iostream>
#include <vector>

using namespace std;

// r4 r1
// r3 r2

//    x1 x2
// y1 
// y2

//     xx1 xx2 xx3
// yy1
// yy2
// yy3

int n; 
vector<vector<int>> v;
bool ok = true;

bool all_zero(int x1, int x2, int y1, int y2) {
    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2; j++) {
            if (v[i][j] != 0) return false;
        }
    }
    return true;
}


int recur(int x1, int x2, int y1, int y2) {
    //cout << x1 << x2 << y1 << y2 << endl;
    if (!ok) return -1;

    if (x2-x1 == 2 && y2-y1 == 2) {
        if (v[x2-1][y2-1] != 0) {
            ok = false;
            return 0;
        }
        int a = v[x1][y1];
        int b = v[x1+1][y1];
        int c = v[x1][y1+1];
        
        //cout << a << b << c << endl;
        if (a == 0 || b == 0 || c == 0) {
            ok = false;
            return 0;
        }
        if (a == b) return a;
        if (b == c) return b;
        if (a == c) return a;
        
        ok = false;
        return 0;
    }

    int xx1 = x1; 
    int xx2 = (x1+x2)/2;
    int xx3 = x2;
    int yy1 = y1;
    int yy2 = (y1+y2)/2;
    int yy3 = y2;

    if (!all_zero(xx2, xx3, yy2, yy3)) { // check zero region
        ok = false;
        return 0;
    }

    //find the number of tridant of region 1 3 4
    int a = recur(xx1,xx2,yy1,yy2);
    int b = recur(xx2,xx3,yy1,yy2);
    int c = recur(xx1,xx2,yy2,yy3);

    if (a == 0 || b == 0 || c == 0) {
        ok = false;
        return 0;
    }

    if (a == b) return a;
    if (b == c) return b;
    if (a == c) return a;

    ok = false;
    return 0;
}

int main() {
    int N = 3;
    while (N--) {
        cin >> n;
        ok = true;
        v.resize(n);
        for (int i = 0 ; i<n ; i++) {
            vector<int> vv(n);        
            for (int j = 0 ; j<n ; j++) {
                int d; cin >> d;
                vv[j] = d;
            }
            v[i] = vv;
        }
        int out  = recur(0, n, 0, n);
        if (ok) {
            cout << out << endl;
        } else {
            cout << 0 << endl;
        }
        
    }
}