#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n , m;
vector<vector<int>> people;
bool ok = false;

void check(vector<int> choose) {
    int cnt = 0;
    vector<bool> c(n);
    for (auto x : choose) {
        for (auto y : people[x]) {
            if (c[y-1] == false) {
                c[y-1] = true;
                cnt++;
            } 
            if (cnt == n) { 
                //cout << people[x].size() << " " << cnt << "\n";
                ok = true;
                return;
            }
        }
    }
}


void recur(int idx , vector<int> &choose , int k ) {
    if (ok) return;

    if (choose.size() == k) {
        check(choose);
        return;
    }
    if (idx == m) {
        return;
    }
    

    choose.push_back(idx);
    recur(idx+1 , choose , k );
    choose.pop_back();

    recur(idx+1 , choose , k );
}



int main() {
    cin >> n >> m;

    for (int i = 0 ; i<m ; i++) {
        int t; cin >> t;
        vector<int> person;
        for (int j = 0 ; j<t ; j++) {
            int tt; cin >> tt;
            person.push_back(tt);
        }
        people.push_back(person);
    }
    sort(people.begin(), people.end() , [] (vector<int> &a , vector<int> &b) {
        return a.size() > b.size();
    });

    for (int i = 1 ; i<=m ; i++) {
        if (!ok) {
            vector<int> choose;
            recur(0 , choose , i);
            if (ok) {
                cout << i;
                break;
            }
         } 
    }



}