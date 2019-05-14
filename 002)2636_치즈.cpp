#include <iostream>
using namespace std;
// 0만나면 확장, 1만나면, check후 0으로 바꾼다.
int a[100][100];
bool c[100][100];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int n, m;
void go(int x, int y){ 
    c[x][y] = true;
    for(int k=0; k<4; k++){
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
        if(c[nx][ny]) continue;
        if(a[nx][ny] == 0){
            // 확장
            go(nx, ny);
        }else if(a[nx][ny] == 1){
            // check후, a[nx][ny] = 0으로 바꾼다.
            c[nx][ny] = true;
            a[nx][ny] = 0;
        }
    }
}
void clear(){
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            c[i][j]=false;
}
int getCnt(){
    int cnt = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(a[i][j]==1)
                cnt += 1;
    return cnt;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> a[i][j];
   int finish=0;
   int count=getCnt(); // 1초후에 모두 녹아버려 0초에 치즈 값을 제대로 갱신 못하는 경우도 따져야 한다.
    while(1){
        go(0,0);     // 가장자리의 테두리는 치즈 못놓인다는 조건이 있다.
        finish++;    // 한번 탐색했으면, time이 증가한다.
        int tmp = getCnt();
        if(tmp==0) break;
        count = tmp;
        clear();
    }
    cout << finish << '\n';
    cout << count << '\n';
    return 0;
}
