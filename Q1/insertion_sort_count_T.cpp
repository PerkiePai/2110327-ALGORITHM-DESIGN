#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int,int> c;

int ins_sort(vector<int> &A) {
    int cnt = 0;
    for (int pos = A.size()-2 ; pos>=0 ; pos--) {
        int tmp = A[pos];
        size_t i = pos+1;
        while (i < A.size() && A[i] < tmp) {
            cnt++;
            A[i-1] = A[i];
            i++;
        }
        A[i-1] = tmp;
    }
    return cnt;
}


int main() {
    int n , m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0 ; i<n ; i++) {
        int d; cin >> d;
        v.push_back(d);
        c[d] = ins_sort(v);
    }
    for (int i = 0 ; i<m ; i++) {
        int d; cin >> d;
        cout << c[d] << "\n";

    }
}