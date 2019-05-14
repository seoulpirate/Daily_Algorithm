#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
const int MAX = 10000;
bool p[MAX+1];
int d[MAX+1];

int check(int x, int y){
  vector<bool> c(MAX+1);
  vector<int> d(MAX+1);
  queue<int> q;
  q.push(x);
  d[x] = 0;
  c[x] = true;
  while(!q.empty()){
    int now_num = q.front(); q.pop();
    string now = to_string(now_num);
    for(int i=0; i<4; i++){
      string next = now;
      for(int k=0; k<=9; k++){
        if(k==0 && i==0) continue;
        next[i] = k+'0';
        int next_num = stoi(next);
        if(!p[next_num] && !c[next_num]){
          c[next_num] = true;
          d[next_num] = d[now_num]+1;
          q.push(next_num);
        }
      }
    }
  }
  return d[y];
}


int main(){
    int t; cin >> t;
    // 소수 구하기 : 에라토스테네스의 체 - 까먹지말자!
    for(int i=2; i*i<=MAX; i++){
        if(!p[i]){
             for(int j=i+i; j<=MAX; j+=i)
                 p[j]=true; // true면 소수가 아니다.
        }
    }
    
    while(t--){
        int n, k; cin >> n >> k;
        cout << check(n, k) << '\n';
    }
}
