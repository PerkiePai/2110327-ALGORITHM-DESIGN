#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n , m , k , w;
vector<int> v , tow;
vector<pair<int,int>> mon;

void atk_mons( vector<pair<int,int>>::iterator it , int x) {
    while ( it != mon.end() && it->first <= x+w ) {
        if ( it->second > 0 ) {
            it->second--;
            return;
        }
        it++;
    }
}

int main() {
    
    cin >> n >> m >> k >> w;

    

    for (int i = 0 ; i < m ; i++) {
        int d; cin >> d;
        v.push_back(d);
    }
    for (auto x : v) {
        int d; cin >> d; 
        mon.push_back({x,d});
    }
    sort(mon.begin() , mon.end());

    for (int i = 0 ; i < k ; i++) {
        int d; cin >> d; 
        tow.push_back(d);
    }
    sort(tow.begin() , tow.end());

    for (auto x : tow) {
        auto it = lower_bound(mon.begin() , mon.end() , make_pair(x-w , 0));
        //cout << it->first << "\n";
        if (it != mon.end()) {
            atk_mons(it , x);
        }    
    }

    int health = 0;
    for (auto x : mon) {
        health += x.second;
    }
    cout << health;

}