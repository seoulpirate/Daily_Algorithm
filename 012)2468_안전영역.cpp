#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <tuple>
using namespace std;
int a[100][100];
int n;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int bfs(int water){
    vector<vector<bool>> c(n, vector<bool>(n));
    // 먼저 물 잠기는 것 먼저 true로 체크
    // 단순 2중 for문으로 가능
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(a[i][j]<=water)
                c[i][j]=true;
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!c[i][j]){
                ans += 1;
                c[i][j] = true;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                while(!q.empty()){
                    int x, y; tie(x, y) = q.front(); q.pop();
                    for(int k=0; k<4; k++){
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if(nx>=0 && nx<n && ny>=0 && ny<n){
                            if(!c[nx][ny]){
                                q.push(make_pair(nx, ny));
                                c[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main(){
    cin >> n;
    int high=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            if(a[i][j]>high) high=a[i][j];
        }
    
    int ans = 0;
    // h=0부터 하는 것은 아무 지역도 물에 잠기지 않을 수 있기 때문이다.
    // 예제에서 h=1이면, 아무지역에도 물이 잠기지 않고 안전한 영역은 1이 된다.
    for(int h=0; h<=high; h++){ 
        int tmp = bfs(h);
        if(ans < tmp) ans = tmp;
    }
    cout << ans << '\n';
    
    return 0;
}
