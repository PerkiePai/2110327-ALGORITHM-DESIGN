#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M; cin >> N >> M;
    vector<ll> tasks(M);
    for (int i=0; i<M; i++) {
        cin >> tasks[i];
    }

    sort(tasks.begin(), tasks.end());

    vector<ll> student_time(N, 0);
    double sum = 0; 

    for (int i=0; i<M ;i++) {
        int idx = i%N;
        student_time[idx] += tasks[i];
        sum += student_time[idx];
    }

    printf("%.4f", sum/M);

}