/**
* Copyright(c)
* All rights reserved
* Author: HanYang
* Date: 2018-08-04-13.14
* input: Array
* output: sorted Array
* Description: no
*/
#include<iostream>
using namespace std;

void mergeArr(int A[],int p,int q, int r)
{
  int i = p, j = q +1, s=0;
  int *result = new int[r-p+1];
  while(i <= q && j <= r) {
    if (A[i] <= A[j]) {
      result[s++] = A[i];
      i++;
    } else {
      result[s++] = A[j];
      j++;
    }
  }
  if (i == q) {
    for (int t = j; t <= r; t++) {
      result[s++] = A[t];
    }
  } else {
      for (int t = i; t <= q; t++) {
        result[s++] = A[t];
      }
  }
  for(int g=0;g<r-p+1;g++) {
    A[g+p] = result[g];
  }
}

void bottomUpSort(int A[], int N)
{
    int i, t, s;
    t = 1;
    while (t < N) {
        s = t; t = 2*s;i = 0;
        while (i + t < N) {
            mergeArr(A, i+1, i + s, i+ t);
            i = i + t;
        }
        if (i + s < N)
            mergeArr(A, i+1, i+s,N);
    }
}

int main()
{
  int A[] = {4,1,8,0,-4,-1,5}, N = sizeof(A) /sizeof(int);
  bottomUpSort(A, N);
  for(int i = 0; i< N; i++) {
    cout<<A[i]<<' ';
  }
  return 0;
}
