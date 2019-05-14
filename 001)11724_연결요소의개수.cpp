#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a[1001];
bool c[1001];

void go(int now){
    c[now] = true;
    for(int next : a[now]){
        if(!c[next])
            go(next);
    }
}

int main(){
    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        a[x].push_back(y); //
        a[y].push_back(x); // vector는 push가 아니라, push_back이다.
    }
    int ans = 0;
    for(int i=1; i<=n; i++)
        if(!c[i]){
            ans+=1;
            go(i);
        }
    cout << ans << '\n';
    return 0;
}
