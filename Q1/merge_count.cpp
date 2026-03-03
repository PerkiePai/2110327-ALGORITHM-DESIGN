#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 1;
int N, K;

void gen_unsort(vector<int>& a, int l , int r) {
    if ((r-l)<=1 ||  cnt >= K) return;

    cnt+=2;

    int mid = (l+r)/2;
    swap(a[mid-1] , a[mid]);
    gen_unsort(a, l, mid);
    gen_unsort(a, mid, r);
}

int main() {
    cin >> N >> K;

    if (K%2==0 || K>2*N-1 ) {
        cout << -1;
        return 0;
    }

    vector<int> a(N);
    for (int i = 0 ; i<N ; i++) {
        a[i] = i+1;
    }
    gen_unsort(a, 0, N);
    for (auto& x: a) {
        cout << x << " ";
    }
}