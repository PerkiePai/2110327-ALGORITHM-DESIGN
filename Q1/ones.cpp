#include <bits/stdc++.h>
using namespace std;

int recur(int n, int digits) {
    if (n==0) return 0;
    if (digits==1) return n;

    int ones = 0;
    for (int i=0; i<digits ; i++) {
        ones = ones*10+1;
    }

    int times = n/ones;
    int left = n%ones;

    int c1 = times*digits + recur(left , digits-1);
    int c2 = (times+1)*digits + recur(ones - left , digits-1);

    return min(c1,c2);
}

int main() {
    int n; cin >> n;

    int temp = n;
    int digits = 0;
    while (temp>0) {
        temp/=10;
        digits++;
    }

    cout << recur(n, digits+1);
}