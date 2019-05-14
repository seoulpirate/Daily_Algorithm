#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int a[1000][1000];
int d[1000][1000];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main(){
    int n, m; cin >> m >> n; // '열' 먼저 입력받음. 일반적으로는 '행'(n)부터 
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> a[i][j];
    
    memset(d, -1, sizeof(d));
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(a[i][j]==1){
                d[i][j]=0;
                q.push(make_pair(i, j));
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
                if(a[nx][ny] == 0 && d[nx][ny]==-1){
                    d[nx][ny] = d[x][y]+1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    
    bool ok = true;
    int ans = 0; // ans의 초기값은 0초이다.
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(a[i][j]==0 && d[i][j]==-1)
                ok = false;
            if(d[i][j] > ans) ans = d[i][j];
        }
    
    if(ok) cout << ans << '\n';
    else cout << -1 << '\n';
    
    return 0;
}
