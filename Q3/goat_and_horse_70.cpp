#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , m;
    cin >> n >> m;
    pair<int,int>S;
    pair<int,int>T;
    vector<vector<char>>field(n,vector<char>(m));
    vector<vector<bool>>check(n,vector<bool>(m,false));
    vector<bool>visited_row(n,false);  
    vector<bool>visited_col(m,false);  
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            char ch;               
            cin >> ch;
            if(ch == 'S') S = {i,j};
            field[i][j] = ch;
        }
    }
    queue<pair<pair<int,int>,int>>bfs;
    bfs.push({S,0});
    while(!bfs.empty()){
    check[S.first][S.second] = true; 
        auto i = bfs.front();
        bfs.pop();
        int x = i.first.first;
        int y = i.first.second;
        if(field[x][y] == 'T') {cout << i.second; return 0;}

        if(x > 0 && !check[x-1][y] && field[x-1][y] != 'X') {bfs.push({{x-1,y},i.second+1}); check[x-1][y] = true;}
        if(x < n-1 && !check[x+1][y] && field[x+1][y] != 'X') {bfs.push({{x+1,y},i.second+1}); check[x+1][y] = true;}
        if(y > 0 && !check[x][y-1] && field[x][y-1] != 'X') {bfs.push({{x,y-1},i.second+1}); check[x][y-1] = true;}
        if(y < m-1 && !check[x][y+1] && field[x][y+1] != 'X') {bfs.push({{x,y+1},i.second+1}); check[x][y+1] = true;}

        if(field[x][y] == '#'){
            if(!visited_col[y]){         
                visited_col[y] = true;
                for(int j = 0; j < n; j++){
                    if(!check[j][y] && field[j][y] != 'X'){
                        bfs.push({{j,y},i.second+1}); check[j][y] = true;
                    }
                }
            }
            if(!visited_row[x]){        
                visited_row[x] = true;
                for(int j = 0; j < m; j++){
                    if(!check[x][j] && field[x][j] != 'X'){
                        bfs.push({{x,j},i.second+1}); check[x][j] = true;
                    }
                }
            }
        }
    }
}