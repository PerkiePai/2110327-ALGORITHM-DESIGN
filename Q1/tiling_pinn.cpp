#include <bits/stdc++.h>

using namespace std;

void tiling(int x,int y,int i,int j,int l){
    if(l==2){
        if(x%2 == 0 && y%2 == 0){
            cout << 0 << " " << j << " " << i << "\n";
        }
        else if(x%2 == 0 && y%2 == 1){
            cout << 1 << " " << j << " " << i << "\n";
        }
        else if(x%2 == 1 && y%2 == 0){
            cout << 2 << " " << j << " " << i << "\n";
        }
        else if(x%2 == 1 && y%2 == 1){
            cout << 3 << " " << j << " " << i << "\n";
        }
        return;
    }
    int midi = i+l/2;
    int midj = j+l/2;
    if(x < midi && y < midj){
        cout << 0 << " " << midj-1 << " " << midi-1 << "\n";
        tiling(x,y,i,j,l/2);
        tiling(midi-1,midj,i,midj,l/2);
        tiling(midi,midj-1,midi,j,l/2);
        tiling(midi,midj,midi,midj,l/2);
    }
    else if(x < midi && y >= midj){
        cout << 1 << " " << midj-1 << " " << midi-1 << "\n";
        tiling(midi-1,midj-1,i,j,l/2);
        tiling(x,y,i,midj,l/2);
        tiling(midi,midj-1,midi,j,l/2);
        tiling(midi,midj,midi,midj,l/2);
    }
    else if(x >= midi && y < midj){
        cout << 2 << " " << midj-1 << " " << midi-1 << "\n";
        tiling(midi-1,midj-1,i,j,l/2);
        tiling(midi-1,midj,i,midj,l/2);
        tiling(x,y,midi,j,l/2);
        tiling(midi,midj,midi,midj,l/2);
    }
    else if(x >= midi && y >= midj){
        cout << 3 << " " << midj-1 << " " << midi-1 << "\n";
        tiling(midi-1,midj-1,i,j,l/2);
        tiling(midi-1,midj,i,midj,l/2);
        tiling(midi,midj-1,midi,j,l/2);
        tiling(x,y,midi,midj,l/2);
    }
}

int main(){
    int l,x,y;
    cin >> l >> x >> y;
    cout << ((l*l)-1)/3 << "\n";
    tiling(y,x,0,0,l);
}