    #include <bits/stdc++.h>
    using namespace std;

    vector<int> mem, c;

    int ap( int idx) { //return cost
        if (idx <= 0) return 0;
        if (mem[idx] != -1) return mem[idx];

        int take = ap(idx-2) + c[idx];
        int skip = ap(idx-1);

        return mem[idx] = max(take , skip);
    }

    int main() {
        int n; cin >> n;
        mem.resize(n+1 , -1); c.resize(n+1);

        for (int i=1; i<=n; i++) {
            cin >> c[i];
        }

        cout << ap(n);

    }