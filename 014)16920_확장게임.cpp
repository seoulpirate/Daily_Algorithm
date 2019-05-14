#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <tuple>
using namespace std;
int a[1000][1000];
queue<pair<int, int>> q[10];
queue<pair<int, int>> nq[10];
int player[10];
int d[1000][1000];
int res[10];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int main(){
    int n, m, p; cin >> n >> m >> p;
    for(int i=1; i<=p; i++)
        cin >> player[i];
    for(int i=0; i<n; i++){
        string line; cin >> line;
        for(int j=0; j<m; j++){
            if(line[j]>='1' && line[j]<='9'){
                int num = line[j]-'0';
                a[i][j] = num;
                q[num].push(make_pair(i, j));
            }
            else if(line[j]=='.'){ a[i][j] = 0; }
            else if(line[j]=='#'){ a[i][j] = -1; }
        }
    }
 
    while(1){
        bool ok = false;
        for(int i=1; i<=p; i++){
            // 각 player별로 현재 담긴 큐를 통해 이동 거리만큼 지도 변화시켜준다.
            // 끝나기 전에 최종 위치만 다음 큐에 넣어준다.
            memset(d, 0, sizeof(d));
            while(!q[i].empty()){
                ok = true;
                int x, y; tie(x, y) = q[i].front(); q[i].pop();
                if(d[x][y]==player[i]) {
                    nq[i].push(make_pair(x, y));
                }
                // a[x][y] = i; // 현재 정점도 일단 찍어줘야...?
                for(int k=0; k<4; k++){
                    int nx = x+dx[k]; int ny = y+dy[k];
                    if(nx>=0 && nx<n && ny>=0 && ny<m){
                        if(a[nx][ny] == 0 /*&& !c[nx][ny]*/){
                            if(d[x][y]+1 <= player[i]){
                                //c[nx][ny] = true;
                                a[nx][ny] = i;
                                d[nx][ny] = d[x][y]+1;
                                q[i].push(make_pair(nx, ny));
                            }
                        }
                    }
                }
            }
            //memset(c, false, sizeof(c));
            q[i] = nq[i];
            nq[i] = queue<pair<int,int>>();
        }
        if(!ok) break;
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(a[i][j]>=0)
                res[a[i][j]]++;
    
    for(int i=1; i<=p; i++)
        cout << res[i] <<' ';
    cout << '\n';
    return 0;
}
