#include <iostream>
#include <vector>

using namespace std;

// 3 pointer sol - from hall of fame
int main() {
    int n,m; cin >> n >> m;
    vector<int> v;
    while (n--) {
        int t; cin >> t;
        v.push_back(t);
    }

    int minn, maxx;

    for (int i = 0; i<m ; i++) {
        int t; cin >> t;
        bool flag = false;

        for (int i = 0; i<v.size()-2 && !flag ;i++) {
            int l = i+1;
            int r = v.size()-1;
            while (l<r) {
                int sum = v[l] + v[r] +v[i];
 
                if (sum == t) {
                    flag = true;
                    break;
                } else if (sum < t) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        (flag) ? cout << "YES\n" : cout << "NO\n";

    }
}