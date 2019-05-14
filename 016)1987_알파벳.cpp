#include <iostream>
#include <string>
#include <vector>
using namespace std;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool alpha[26];
int n, m;
int go(vector<string> &a, int x, int y){
    int ans = 0;
    alpha[a[x][y]-'A']=true;
    for(int k=0; k<4; k++){
        int nx = x+dx[k]; int ny = y+dy[k];
        if(nx>=0 && nx<n && ny>=0 && ny<m){
            if(!alpha[a[nx][ny]-'A']){
                alpha[a[nx][ny]-'A'] = true; // BF-백트래킹 호출 하기전, True.
                int tmp = go(a, nx, ny);
                if(tmp > ans) ans = tmp;
                alpha[a[nx][ny]-'A'] = false; // BF-백트래킹 호출 끝나면, False.
            }
        }
    }
    return ans+1;
}
int main(){
    cin >> n >> m;
    vector<string> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    alpha[a[0][0]-'A']=true;
    cout << go(a, 0,0) << '\n';
    return 0;
}
