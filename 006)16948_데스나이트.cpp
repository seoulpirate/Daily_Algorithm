#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
int d[201][201];
int dx[]={-2, -2, 0, 0, 2, 2};
int dy[]={-1, 1, -2, 2, -1, 1};
int main(){
    int n; cin >> n;
    memset(d, -1, sizeof(d));
    int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
    d[sx][sy] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for(int k=0; k<6; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if(d[nx][ny]!=-1) continue;
            d[nx][ny] = d[x][y]+1;
            q.push(make_pair(nx, ny));
        }
    }
    
    cout << d[ex][ey] << '\n';
    return 0;    
}
