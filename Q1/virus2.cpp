#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool ok = true;

int recur(string s) {
    if (!ok) return -1;
    if (s.size() == 2) {
        int cnt = 0;
        for (auto &x : s) {
            if (x == '1') {
                cnt++;
            }
        }
        //cout << cnt << endl;
        return cnt;
    }

    int i1 = recur(s.substr(0, s.size()/2));
    int i2 = recur(s.substr(s.size()/2));

    if (abs(i1 - i2) > 1) {
        ok = false;
        return -1;
    }
    return i1+i2;
}

int main() {
    int n,m; cin >> n >> m;
    while (n--) {
        string s = "";
        for (int i = 0; i<pow(2,m); i++) {
            string d; cin >> d;
            s+=d;
        }
        ok = true;
        recur(s);
        cout << ((ok ? "yes\n" : "no\n"));    
    }
}