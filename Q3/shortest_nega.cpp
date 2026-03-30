#include <bits/stdc++.h>
using namespace std;

//floyd warshell

int main() {
    int N,E,s; cin >> N >> E >> s;
    vector<vector<int>> dist(N, vector<int>(N, INT_MAX/4)); //INT_MAX/4 cause it will overflow when dist[i][k] + dist[k][j]

    for (int i=0; i<N; i++) {
        dist[i][i] = 0; // edge to itself is 0
    }

    for (int i=0; i<E; i++) {
        int a,b,c; cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c); //in case of multiple edge -> choose the smallest 
    }

    //floyd start
    for (int k=0; k<N; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                dist[i][j] = min( dist[i][j] , dist[i][k]+dist[k][j] ); // check which path shorter, i->j or i->k->j
            }
        }
    }

    //negative cycle check
    for (int i=0; i<N; i++) {
        if (dist[i][i] < 0) {
            cout << -1;
            return 0;
        }
    }

    //print
    for (int v = 0; v < N; v++) {
        if (v) cout << " ";
        cout << (dist[s][v] >= INT_MAX ? INT_MIN : (int)dist[s][v]);
    }


}