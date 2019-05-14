#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;
int a[100][100][100];
int d[100][100][100];
int dx[]={0,0,0,0,-1,1};
int dy[]={0,0,-1,1,0,0};
int dz[]={-1,1,0,0,0,0};
int main(){
    int n, m, h; cin >> m >> n >> h;
    for(int i=0; i<h; i++)
        for(int j=0; j<n; j++)
            for(int l=0; l<m; l++)
                cin >> a[i][j][l];
    
    queue<tuple<int, int, int>> q;
    memset(d, -1, sizeof(d));
    for(int i=0; i<h; i++)
        for(int j=0; j<n; j++)
            for(int l=0; l<m; l++){
                if(a[i][j][l]==1){
                    d[i][j][l]=0;
                    q.push(make_tuple(i, j, l));
                }
            }
    
    while(!q.empty()){
        int z, x, y; tie(z, x, y) = q.front();
        q.pop();
        for(int k=0; k<6; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            int nz = z+dz[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && nz>=0 && nz<h){
                if(a[nz][nx][ny]==0 && d[nz][nx][ny]==-1){
                    d[nz][nx][ny] = d[z][x][y]+1;
                    q.push(make_tuple(nz, nx, ny));
                }
            }
        }
    }
    
    bool ok = true;
    int ans = 0;
    for(int i=0; i<h; i++)
        for(int j=0; j<n; j++)
            for(int l=0; l<m; l++){
                if(a[i][j][l]==0 && d[i][j][l]==-1) ok=false;
                if(d[i][j][l] > ans) ans = d[i][j][l];
            }
                
    if(ok) cout << ans << '\n';
    else cout << -1 << '\n';
    return 0;
}
