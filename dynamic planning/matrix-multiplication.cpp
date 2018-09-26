/**
* Copyright(c)
* All rights reserved
* Author: hy
* Date: 2018-09-26-18.08
*/
#include<iostream>
using namespace std;
int n;

void Traceback(int i, int j, int(*s)[100])
{
    if (i==j) {
        cout<<"A"<<i;
        return;
    }
    if (i>1 || j<n) cout<<"(";
    Traceback(i,s[i][j],s);
    Traceback(s[i][j]+1,j,s);
    if (i>1 || j<n) cout<<")";
}

int main()
{
  int p[100] = {0};
  cin>>n;
  if(n==1) {
    cin>>p[0];
  } else {
      for(int i=0;i<=n;i++) {
        cin>>p[i];
      }
  }
  // 表示最小数乘次数
  int m[100][100] = {0};
  // 相应的最小数乘次数对应的断开位置
  int s[100][100] = {0};
  for(int r=2;r<=n;r++) {
    for(int i=1;i<=n-r+1;i++) {
        // Important
        int j = i+r-1;
        m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
        s[i][j]=i;
        for(int k=i+1;k<j;k++) {
            int temp = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
            if(temp<m[i][j]) {
                m[i][j] = temp;
                s[i][j] = k;
            }
        }
    }
  }
  cout<<m[1][n]<<endl;
  Traceback(1,n,s);
  cout<<endl;
  return 0;
}
