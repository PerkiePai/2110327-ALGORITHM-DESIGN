#include <iostream>

using namespace std;


int mod_expo(int x , int n , int k) {
    if (n == 1) return x%k;

    if (n%2 == 1) {
        return (mod_expo(x , n/2 , k) * mod_expo(x , n/2+1 , k)) % k;
    } else {
        return (mod_expo(x , n/2 , k) * mod_expo(x , n/2 , k)) % k;
    }
}

int main() {
    int x, n, k; cin >> x >> n >> k;
    cout << mod_expo(x , n , k);
}