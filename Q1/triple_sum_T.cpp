#include <iostream> 
#include <vector>
#include <unordered_set>

using namespace std;

int n,m;
vector<int> v;
unordered_set<int> s;

void recur(int idx , int sum, int cnt) {
    

    if (cnt == 3) {
        s.insert(sum);
        return;
    }

    if (idx >= n) return;

    for (int i = idx+1 ; i<n ; i++) {

        recur(i , sum + v[i] , cnt+1);

    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 0 ; i<n ; i++) {
        int t; cin >> t;
        v.push_back(t);
    }

    for (int i = 0 ; i<n ; i++) {

        recur(i , v[i] , 1);

    }

    // //debugging
    // cout << s.size() << endl;
    // for (auto &x : s) {
    //     cout << x << " ";
    // }
    // cout << "\n";
    // //

    while (m--) {
        int t; cin >> t;
        if (s.find(t) != s.end()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

}