#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> a[3000];
int c[3000]; // c가 현재 무엇인지에 따라 리턴 값을 변경해서 cycle을 따로 파악할 수 있다.
int go(int now, int prev){ // prev를 지정해줘야 현재 지점에서 이전에 왔던 칸 재방문 안한다.
    if(c[now] == 1) return now;
    else{
        c[now] = 1;
        for(int next : a[now]){
            if(next == prev) continue;
            int res = go(next, now);       
            if(res == -2) return -2; 
            if(res >= 0){
                c[now] = 2;
                if(res==now) return -2;
                else return res;
            }
        }
    }
    return -1;
}
int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int x, y; cin >> x >> y; 
        x-=1; y-=1;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
    go(0, -1);
    
    vector<int> d(n, -1);
    queue<int> q;
    for(int i=0; i<n; i++){
        if(c[i]==2){ d[i]=0; q.push(i); }
    }
    
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(int next : a[now]){
            if(d[next]==-1){
                d[next]=d[now]+1;
                q.push(next);
            }
        }
    }
    
    for(int i=0; i<n; i++)
        cout << d[i] << ' ';
    cout << '\n';
    return 0;    
}

