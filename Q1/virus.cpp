#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool valid(string s, int k) {
    if (k == 1) return s=="01";

    int mid = s.size()/2;
    string l = s.substr(0,mid);
    string r = s.substr(mid);

    if (!valid(r,k-1)) return false;

    string revL = l;
    reverse(revL.begin() , revL.end());
    
    return valid(l, k-1) || valid(revL, k-1);
}

int main() {
    int n,k; cin >> n >> k;
    while (n--) {
        string in = "";
        int ii = pow(2,k);
        while (ii--) {
            string t; cin >> t;
            in += t;
        }
        cout << (valid(in,k) ? "yes" : "no") << endl;
    }
}