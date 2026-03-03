#include <iostream>
#include <vector>

using namespace std;


vector<long long > multi(vector<long long > v1 , vector<long long > v2, long long k) {
    long long & a = v1[0];
    long long & b = v1[1];
    long long & c = v1[2];
    long long & d = v1[3];
    long long & w = v2[0];
    long long & x = v2[1];
    long long & y = v2[2];
    long long & z = v2[3];
    long long o1 = a*w+b*y;
    long long o2 = a*x+b*z;
    long long o3 = c*w+d*y;
    long long o4 = c*x+d*z;
    vector<long long > out;
    out.push_back(o1%k); out.push_back(o2%k); out.push_back(o3%k); out.push_back(o4%k);
    return out;
}

vector<long long > power(vector<long long > v ,long long  n, long long k) {
    if (n==1) return v;

    vector<long long > temp = power(v, n/2, k);
    if (n%2 == 0) {
        return multi(temp, temp, k);
    } else {
        return multi(multi(temp, temp, k),v, k);
    }
}

// vector<int> mod(vector<int> v) {
    
// }

int main() {
    long long  n, k; cin >> n >> k;
    long long  a, b, c, d; cin >> a >> b >> c >> d;
    vector<long long > v;
    v.push_back(a); v.push_back(b); v.push_back(c); v.push_back(d);
    v = power(v, n, k);

    for (auto &x : v) {
        cout << x << " ";
    }

} 