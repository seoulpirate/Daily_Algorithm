#include <iostream>
#include <set>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
int a[1000][1000];
int group[1000][1000];
int res[1000*1000+10];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int n, m;
void bfs(int x, int y, int num){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    group[x][y]=num;
    while(!q.empty()){
        int x, y; tie(x,y)=q.front(); q.pop();
        for(int k=0; k<4; k++){
            int nx=x+dx[k]; int ny=y+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(a[nx][ny]==1 && group[nx][ny]==-1){
                    group[nx][ny]=num;
                    // bfs(nx, ny, num); // 왜 DFS를 호출했지?!
                    q.push(make_pair(nx, ny));
                }   
            }                
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> a[i][j];
    
    memset(group, -1, sizeof(group));
    int cnt = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(a[i][j]==1 && group[i][j]==-1) bfs(i, j, ++cnt);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(group[i][j]>0) res[group[i][j]]+=1;
    
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]==0){        // 칸을 뚫어 4방향 연결지점으로 확장 가능한지 따지는 문제
                set<int> near;
                for(int k=0; k<4; k++){
                    int nx = i+dx[k]; int ny = j+dy[k];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && group[nx][ny]>0){
                        near.insert(group[nx][ny]);
                    }
                }
                int sum = 1;
                for(int index : near)
                    sum+=res[index];
                if(sum>ans) ans = sum;
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}
