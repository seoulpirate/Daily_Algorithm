#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 100000;
bool visited[MAX+1];
bool finished[MAX+1];
int a[MAX+1];
int cnt = 0;
void go(int now){
    visited[now]=true;
    int next = a[now];
    if(!visited[next]){
        go(next);
    }else if(!finished[next]){
        for(int i=next; i!=now; i=a[i]) cnt++;
        cnt++;
    }
    finished[now]=true;
}
int main(){
    int t; cin>>t;
    while(t--){
        memset(visited, 0, sizeof(visited));
        memset(finished, 0, sizeof(finished));
        cnt = 0;
        int n; cin >> n;
        for(int i=0; i<n; i++){
            int x; cin >> x; x-=1;
            a[i]=x; 
        }
        int sum=0;
        for(int i=0; i<n; i++){
            if(!visited[i])
                go(i);
        }
        cout << n-cnt << '\n';        
    }
    return 0;
}
