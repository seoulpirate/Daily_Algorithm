#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAX=500000;
int d[MAX+1][2];

int main(){
    int n, m; cin >> n >> m;
    memset(d, -1, sizeof(d));
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    d[n][0] = 0;
    while(!q.empty()){
        int now = q.front().first;
        int t = q.front().second;
        q.pop();
        for(int next : {now-1, now+1, now*2}){
            if(0<=next && next<=MAX){
                if(d[next][1-t]==-1){
                    d[next][1-t] = d[now][t]+1;
                    q.push(make_pair(next, 1-t));
                }
            }
        }
    }
    
    int ans = -1;
    for(int t=0; ;t++){
        m+=t;
        if(m>MAX) break;
        if(d[m][t%2]<=t){
            ans = t;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}
