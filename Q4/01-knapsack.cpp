#include <bits/stdc++.h>
using namespace std;

double max_cur_v = 0.0;
double W;
int N;

struct item {
    double v;
    double w;
    double ratio;
};

bool comp(const item &a, const item &b) {
    return a.ratio > b.ratio;
}

vector<double> v;
vector<double> w;
vector<item> items;
//vector<double> maxxV; //max possible from i to the end (prunning)

double heuristic(int idx, double remain_w) {
    if (remain_w <= 0) return 0;
    double bound_v = 0;
    for (int i=idx; i<N; i++) {
        if (items[i].w <= remain_w) {
            remain_w -= items[i].w;
            bound_v += items[i].v;
        } else {
            bound_v += items[i].v * ( remain_w / items[i].w );
            break;
        }
    }
    return bound_v;
}

void kp(int idx, double cur_w, double cur_v) {
    if (cur_w > W + 1e-9) return;

    if (max_cur_v < cur_v) {
        max_cur_v = cur_v;
    }

    if (idx == N) return;

    //if (cur_v + maxxV[idx] <= max_cur_v) return;
    if (cur_v + heuristic(idx, W-cur_w) <= max_cur_v + 1e-9) return;

    kp( idx+1 , cur_w+items[idx].w, cur_v+items[idx].v );
    kp( idx+1 , cur_w, cur_v );
}

int main() {
    cin >> W >> N; 
    v.resize(N);
    w.resize(N);
    items.resize(N);
    //maxxV.resize(N+1);

    for (int i=0; i<N; i++) { //values
        cin >> v[i];
    }
    for (int i=0; i<N; i++) { //weights
        cin >> w[i];
    }

    for (int i=0; i<N; i++) {
        items[i] = { v[i], w[i], v[i]/w[i] };
    }

    sort(items.begin(), items.end(), comp);

    // for (int i=N-1; i>=0; i--) {
    //     maxxV[i] = maxxV[i+1]+v[i];
    // }

    kp(0,0,0);

    printf("%.4f",max_cur_v);

}