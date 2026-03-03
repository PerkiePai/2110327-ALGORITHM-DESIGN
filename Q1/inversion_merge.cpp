#include <iostream>
#include <vector>

using namespace std;

int merge_count(vector<int> &a , vector<int> &temp , int l , int r) {
    if (r-l <= 1) return 0;

    int mid = (l+r)/2;
    int cnt = 0;
    cnt += merge_count(a , temp , l , mid);
    cnt += merge_count(a , temp , mid , r);

    int i = l; //left array
    int j = mid; //right array
    int k = l; //temp

    while (i<mid && j<r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            cnt += mid-i;
        }
    }

    while (i<mid) temp[k++] = a[i++];
    while (j<r) temp[k++] = a[j++];

    for (int i = l ; i<r ; i++) {
        a[i] = temp[i];
    }
    return cnt;
}

int main() {
    int N; cin >> N;
    vector<int> v(N) , temp(N);
    for (int i = 0 ; i<N ; i++) {
        int t; cin >> t;
        v[i] = t;
    }

    cout << merge_count(v , temp , 0 , N);
}