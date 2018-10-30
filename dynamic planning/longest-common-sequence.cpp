/**
* Copyright(c)
* All rights reserved
* Author: hy
* Date: 2018-10-10-18.41
*/
#include<iostream>
using namespace std;

void LCS_length(int m, int n, char *x, char *y, int c[50][50], int b[50][50])
{
    int i,j;
    for(i=0;i<=m;i++) c[i][0]=0;
    for(j=0;j<n;j++) c[0][j]=0;
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++) {
        if(x[i]==y[j]) {c[i][j] = c[i-1][j-1] + 1;b[i][j]=1;}
        else if(c[i-1][j]>=c[i][j-1]) {c[i][j]=c[i-1][j];b[i][j]=2;}
        else {c[i][j]=c[i][j-1];b[i][j]=3;}
    }
}

void printLcs(int i, int j, char *x,int b[50][50])
{
    if(i==0||j==0) return ;
    if(b[i][j]==1){
        printLcs(i-1,j-1,x,b);
        cout<<x[i];
    }
    else if(b[i][j]==2) printLcs(i-1,j,x,b);
    else printLcs(i,j-1,x,b);
}

int main()
{
  char a[50], b[50];
  int lcs[50][50] = {0};
  int path[50][50] = {0};
  int sum ;
  int m, n;
  cin>>sum;
  while(sum>0) {
   cin>>m>>n;
   for(int i=1; i<=m;i++) {
    cin>>a[i];
   }
   for(int j=1;j<=n;j++) {
    cin>>b[j];
   }
   LCS_length(m,n,a,b,lcs,path);
   cout<<lcs[m][n]<<endl;
   printLcs(m,n,a,path);
   cout<<endl;
   sum--;
  }
  return 0;
}
