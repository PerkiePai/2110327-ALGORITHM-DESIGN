#include <iostream> 
#include <vector>

using namespace std;


vector<int> v;

int bsearch(int t, int l, int r) {
    while (l<r-1) {
        
        int mid = (l+r)/2;
        if (v[mid] == t) {
            return v[mid];
        } else if (v[mid] < t) {
            l = mid;
        } else {
            r = mid;
        }

    }

    return (v[l]>t) ? -1 : v[l];
}


int main() {
    int n,m; cin >> n >> m;
    
    while (n--) {
        int d; cin >> d;
        v.push_back(d);
    }

    while (m--) {
        int t; cin >> t;
        cout << bsearch(t, 0, v.size()) << endl;
    }
}