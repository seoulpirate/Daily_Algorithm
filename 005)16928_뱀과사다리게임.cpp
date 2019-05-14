#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int a[101];
int d[101];
int main(){
    int n, m; cin >> n >> m;
    for(int i=1; i<=100; i++){
        a[i]=i; d[i]=-1;
    }
    for(int i=0; i<n+m; i++){
        int x, y; cin >> x >> y;
        a[x] = y;
    }
    d[1]=0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(int k=1; k<=6; k++){
            if(now+k > 100) continue;
            int next = a[now+k];
            if(d[next]==-1){ // 방문을 안한 칸을 방문해야지, bfs가 유효하다.
                d[next]=d[now]+1;
                q.push(next);
            }
        }
    }
    cout << d[100] << '\n';
    return 0;
}
