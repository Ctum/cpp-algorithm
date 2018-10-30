/**
* Copyright(c)
* All rights reserved
* Author: hy
* Date: 2018-10-30-20.13
*/
#include<iostream>
#include<stack>
#define inf 1e9+7
using namespace std;


int main()
{
  int n, m, v;
  // n 表示点的个数 v, m 分别表示源点和终点
  int c[50][50], dist[50];
  // c 表示权 dist 表示最短路径
  bool s[50] = { false };
  // s 表示是否加入到集合s
  int prev[50] = {0};
  cin>>n;
  for(int i=1;i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        cin>>c[i][j];
        if (c[i][j] == -1) {
            c[i][j] = inf;
        }
    }
  }
  cin>>v>>m;
  for (int i=1; i<= n; i++) {
    dist[i] = c[v][i];
    s[i] = false;
    if (dist[i] == inf) prev[i] = 0;
    else prev[i] = v;
  }
  dist[v] = 0; s[v] = true;
  // 把 v 加入到集合 s 中
  for(int i=1; i<n; i++){
    //找到当前最短路
    int temp = inf;
    int u = v;
    for(int j=1; j<=n; j++){
        if(!s[j] && dist[j]<temp){
            temp = dist[j];
            u = j;
        }
    }
    s[u] = true;
    //更新最短路
    for(int j=1; j<=n; j++){
        if(!s[j] && c[u][j]<inf){
            if(dist[u]+c[u][j] < dist[j]){
                dist[j] = dist[u]+c[u][j];
                prev[j] = u;
            }
        }
    }
  }
  cout<<"The least distance from "<<v<<"->"<<m<<" "<<dist[m]<<endl;
  int co = m;
  stack<int> path;
  while(co!=v){
    path.push(co);
    co = prev[co];
  }
  cout<<"the path is "<<v<<"->";
  cout<<path.top();
  path.pop();
  while(!path.empty()) {
    cout<<"->"<<path.top();
    path.pop();
  }
  cout<<endl;
  return 0;
}
