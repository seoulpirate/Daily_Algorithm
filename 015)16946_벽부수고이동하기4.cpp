#include <iostream>
#include <tuple>
#include <set>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int a[1000][1000];
int group[1000][1000];
int res[1000*1000+10];
int n, m;
void bfs(int x, int y, int cnt){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    group[x][y] = cnt;
    while(!q.empty()){
        int x, y; tie(x, y)=q.front(); q.pop();
        for(int k=0; k<4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(a[nx][ny] == 0 && group[nx][ny]==-1){
                    group[nx][ny]=cnt;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}
int main(){
    cin >> n >> m;
     for(int i=0; i<n; i++){
    	string line; cin >> line;
    	for(int j=0; j<m; j++){
    		a[i][j] = line[j]-'0';
    	}
    }
    memset(group, -1, sizeof(group));
    int cnt = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(a[i][j]==0 && group[i][j]==-1)
                bfs(i, j, ++cnt);
        }
    
    
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(group[i][j] > 0)
                res[group[i][j]]+=1;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]==0) cout << a[i][j];
            else{
                set<int> near;
                for(int k=0; k<4; k++){
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if(nx>=0 && nx<n && ny>=0 && ny<m){
                        if(group[nx][ny]>0)
                            near.insert(group[nx][ny]); // near에 무엇을 insert 할지 알아야. 
                    }
                }
                int cnt = 1;
                for(int idx : near){
                    // idx가 무슨 의미 인지 알아야. cnt가 제대로 들어가게 된다.
                    cnt += res[idx];                    
                }
                cout << cnt % 10;
            }
        }
        cout << '\n';
    }
    
    return 0;
}
