#include <iostream> 
#include <vector> 
#include <map> 

using namespace std;

int n,m;
map<int,int> cons;

void print(vector<int> s) {
    for (auto x : s) {
        cout << to_string(x) << " ";
    }
    cout << "\n";
}

void recur(vector<int> s , vector<bool> v) {

    //print(s);

    if (s.size() == n) {
        print(s);
        return;
    }

    for (int i = 0 ; i<n ; i++) {
        if (v[i]) continue;

        if (cons.find(i) != cons.end() && !v[cons[i]]) {
            continue;
        } 

        auto x = s;
        x.push_back(i);
        auto y = v;
        y[i] = true;
        recur(x , y);
    }
}

int main() {
    cin >> n >> m;
    while (m--) {
        int before, after;
        cin >> before >> after;
        cons[after] = before;
    }

    vector<int> s;
    vector<bool> v(n);

    recur(s , v);

}