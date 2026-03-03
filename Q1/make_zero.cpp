#include <iostream> 
#include <queue>

using namespace std; 

int main() {
    int size = 1;
    int cnt = 0;
    queue<int> q;
    int d; cin >> d;
    q.push(d);
    bool ok = false;


    while (true) {
        for (int i = 0 ; i<size ; i++) {
            int t = q.front(); q.pop();
            if ((t+1)%16777216 == 0 || (t*2)%16777216 == 0) {
                ok = true;
                break;
            } else {
                q.push((t+1)%16777216);
                q.push((t*2)%16777216);
            }
        }
        if (ok) {
            break;
        }
        cnt++;
        size*=2;
    }
    cout << cnt;

}