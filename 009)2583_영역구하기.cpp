#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[101][101];
int d[101][101];
int group[100*100+1];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int n, m;
void go(int x, int y, int groupn){
    d[x][y]=groupn;
    for(int k=0; k<4; k++){
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(nx>=0 && nx<n && ny>=0 && ny<m){
            if(d[nx][ny]==-1 && a[nx][ny]==0)
                go(nx, ny, groupn);
        }
    }
}
int main(){
    // 입력으로 주어진 정보를 내 입맛에 맞게 바꾸자.
    int k; cin >> n >> m >> k;
    while(k--){
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        y2-=1; x2-=1;
        for(int i=x1; i<=x2; i++)
            for(int j=y1; j<=y2; j++)
                a[i][j] = 1;
    }
    memset(d, -1, sizeof(d));
    int cnt = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(a[i][j]==0 && d[i][j]==-1){
                go(i, j, ++cnt);
            }
        }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(d[i][j]!=-1)
                group[d[i][j]]+=1;
    sort(group+1, group+cnt+1);
    cout << cnt << '\n';
    for(int i=1; i<=cnt; i++)
        cout << group[i] << ' ';
    cout << '\n';
    return 0;
}
