#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int n, l, r;
bool bfs(vector<vector<int>> &a){
    bool ok = false; // 모든 좌표 탐색했는데, 국경선이 한번도 안열렸다면 false를 반환.
    vector<vector<bool>> c(n, vector<bool>(n, false));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!c[i][j]){
                c[i][j] = true;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                vector<pair<int, int>> info; // 처음에는 tuple로 해서 (x, y, a[x][y]) 저장을 떠올림.
                info.emplace_back(i, j);
                int sum = a[i][j];                
                while(!q.empty()){
                    int x = q.front().first; int y = q.front().second;
                    q.pop();
                    for(int k=0; k<4; k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if(nx>=0 && nx<n && ny>=0 && ny<n){
                            if(!c[nx][ny]){
                                int diff = a[nx][ny] - a[x][y];
                                if(diff<0) diff = -diff;
                                if(l<=diff&&diff<=r){
                                    // 국경선이 열리므로 이에 대한 정보 저장.
                                    info.emplace_back(nx, ny);
                                    sum+=a[nx][ny];
                                    c[nx][ny]=true;
                                    q.push(make_pair(nx, ny));
                                    ok = true; // 국경선이 한번이라도 열렸으니, 현재 turn에는 true다.
                                }
                            }
                        }
                    }
                }
                
                // 국경선 다 열어놓고, 좌표들 집합을 평준화한다.
                int value = sum/info.size();
                for(auto &p : info){
                    int x, y; tie(x, y) = p;
                    a[x][y] = value;
                }
            }
        }
    }
    return ok; // return 변수 제대로 넘겨줄 것!
}
int main(){
    cin >> n >> l >> r;
    vector<vector<int>> a(n, vector<int>(n)); // vector 2차원 할당! 까먹지 말자!
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> a[i][j];
    
    int ans = 0;
    while(1){
        if(!bfs(a)) break;
        ans+=1;
    }
    cout << ans << '\n';
    return 0;
}
