#include <iostream>
#include <set>
#include <string>
#include <cmath>

using namespace std; 

int n, k;
set<string> s;

string inv(string c) {
    string re = "";
    for (auto &x : c) {
        re = x + re;
    }
    return re;
}

void gen(int cnt) {
    if (cnt >= k) return;

    set<string> stemp;

    for (auto ait = s.begin() ; ait != s.end() ; ait++) {
        for (auto bit = s.begin() ; bit != s.end() ; bit++) {
            if (ait != bit) {
                stemp.insert(*ait+*bit);
                stemp.insert(inv(*ait)+*bit);
            } else {
                stemp.insert(inv(*ait)+*bit);
                stemp.insert(*ait+*bit);
            }
        }
    }

    s = stemp;

    cnt++;

    gen(cnt);
}

int main() {
    cin >> n >> k;
    s.insert("01");
    gen(1);

    // for (auto &x : s) {
    //     cout << x << " ";
    // }

    while (n--) {
        string in = "";
        int t = pow(2,k);
        while (t--) {
            string d; cin >> d;
            in += d;
        }
        cout << ((s.find(in) != s.end()) ? "yes" : "no") << endl;
    }

}