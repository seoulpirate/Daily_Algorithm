#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int n;
int a[20][20];

tuple<int, int, int> bfs(int x, int y, int size){
    // 현재 위치에서 상어가 갈 수 있는 경로 다 따져보고, 벡터에 담아두고 나중에 정렬해서 첫번째만 리턴해준다.
    vector<vector<int>> d(n, vector<int>(n, -1));
    vector<tuple<int, int, int>> res; // (d[x][y], x, y)
    queue<pair<int, int>> q; // 템플릿 잘 쓰자! 까먹지 말자!
    q.push(make_pair(x, y));
    d[x][y]=0;
    bool ok = false;
    while(!q.empty()){
        int x, y; tie(x, y) = q.front();
        q.pop();
        for(int k=0; k<4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if(a[nx][ny] > size) continue;
            if(d[nx][ny]!=-1) continue;
            // 남은 경우는 '통과'던지 '먹던지'이다.            
            d[nx][ny] = d[x][y]+1;
            q.push(make_pair(nx, ny));
            if(a[nx][ny] < size && a[nx][ny] != 0){
                // 먹자.
                ok = true; // 한번이라도 먹었으면 현재Turn은 유효하다.
                res.emplace_back(d[nx][ny], nx, ny);
            }
        }
    }
    if(!ok) return make_tuple(-1,-1,-1);
    // res에는 잡아먹은 물고기 경로별로 가장 작은 순서로 정렬해야.
    sort(res.begin(), res.end());
    return res[0];
}

 

int main(){

    cin >> n; int x, y;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            if(a[i][j]==9){ x=i; y=j; a[i][j] = 0;}
        }   

    int ans = 0, size = 2;
    int cnt = 0;
    while(1){
        int nx, ny, time; 
        tie(time, nx, ny) = bfs(x, y, size);
        if(nx==-1 && ny==-1) break;
        cnt += 1;
        ans += time;
        a[nx][ny] = 0; // a[x][y]=0이 아니다. 그러면 계속 Loop 돈다.
        x=nx; y=ny;
        if(size == cnt) { size+=1; cnt = 0; }
    }
    cout << ans << '\n';
    return 0;

}
