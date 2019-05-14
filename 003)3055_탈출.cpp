#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int water[50][50];
int d[50][50];
int n, m; 
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

int main(){
    cin >> n >> m;
    vector<string> a(n);
    memset(d, -1, sizeof(d));    
    memset(water, -1, sizeof(water));
    queue<pair<int, int>> q;
    int sx, sy, ex, ey;
    for(int i=0; i<n; i++){
        cin >> a[i];
        for(int j=0; j<m; j++){
            if(a[i][j] == 'S'){
                sx = i; sy = j;   
            }else if(a[i][j] == 'D'){
                ex = i; ey = j;
            }else if(a[i][j] == '*'){
                water[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }    
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(a[nx][ny]=='.' && water[nx][ny]==-1){
                    q.push(make_pair(nx, ny));
                    water[nx][ny] = water[x][y]+1;
                }
            }
        }
    }    
    
    d[sx][sy]=0;
    q.push(make_pair(sx, sy));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(d[x][y]+1>=water[nx][ny] && water[nx][ny]!=-1) continue;
            if(d[nx][ny]!=-1) continue;
            if(a[nx][ny]=='X') continue; // 문제의 조건을 빼먹었다.
            d[nx][ny] = d[x][y]+1;
            q.push(make_pair(nx, ny));
        }
    }
    
    if(d[ex][ey] != -1) cout << d[ex][ey] << '\n';
    else cout << "KAKTUS" << '\n';
    
    return 0;    
}
