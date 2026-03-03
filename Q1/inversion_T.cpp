#include <iostream>
#include <set>

using namespace std;

int main() {
    int N; cin >> N;
    int cnt = 0;
    multiset<int> s;
    while (N--) {
        int t; cin >> t;
        auto it = s.insert(t);
        cnt += distance(it,s.end())-1;
    }
    cout << cnt;
}   