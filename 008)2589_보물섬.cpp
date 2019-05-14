#include <iostream>
#include <string>
#include <cstring>
#include <tuple>
#include <queue>
using namespace std;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int a[50][50];
int n, m;

int bfs(int x, int y){  
    int d[50][50];
    memset(d, -1, sizeof(d));
    queue<pair<int, int >> q;
    q.push(make_pair(x, y));
    d[x][y] = 0;
    while(!q.empty()){
        int x, y; tie(x,y)=q.front();
        q.pop();
        for(int k=0; k<4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(a[nx][ny]==1) continue;
            if(d[nx][ny]!=-1) continue;
            d[nx][ny]=d[x][y]+1;
            q.push(make_pair(nx,ny));
        }
    }
    
    // 전체 탐색해서 가장 큰 값을 cnt로 저장
    int cnt = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        	if(d[i][j] > cnt) cnt = d[i][j];
    
    return cnt;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<m; j++){
            if(s[j] == 'W')
                a[i][j]=1;                
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]==0){
                int tmp = bfs(i, j);
                if(tmp>ans) ans = tmp;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
