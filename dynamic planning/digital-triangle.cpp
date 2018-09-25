/**
* Copyright(c)
* All rights reserved
* Author: hy
* Date: 2018-09-25-20.06
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
  ifstream input("input.txt");
  ofstream output("output.txt");
  int n;
  int s[101][101] = {0};
  input>>n;
  for(int i = 1; i<= n;i++) {
    for(int j=1; j<=i;j++) {
        input>>s[i][j];
    }
  }
  int max[101][101] = {0};
  for(int i=1;i<=n;i++) {
    // 初始化，使最下面一层的值为max
    max[n][i] = s[n][i];
  }
  for(int i = n-1;i>=1;i--) {
    for(int j=1;j<=i;j++) {
        int left = max[i+1][j];
        int right = max[i+1][j+1];
        if (left>right) {
            max[i][j] = s[i][j] + left;
        } else {
            max[i][j] = s[i][j] + right;
        }
    }
  }
  output<<max[1][1];
  input.close();
  output.close();
  return 0;
}
