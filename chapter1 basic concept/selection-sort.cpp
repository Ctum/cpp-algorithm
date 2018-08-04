/**
* Copyright(c)
* All rights reserved
* Author: HanYang
* Date: 2018-08-04-09.47
* input: n个元素的数组
* output: 按升序排列的数组
* Description: 选择排序
*/
#include<iostream>
using namespace std;

void selectionSort(int A[], int N)
{
    int i,j,k,t;
    for (i = 0; i< N; i++) {
        k = i;
        for (j = i+1; j< N;j++) {
            if (A[j] < A[k])
                k = j;
        }
        if (k != i) {
            t = A[k];
            A[k] = A[i];
            A[i] = t;
        }
    }
}

int main()
{
  int A[] = {1,7,3,34,26,87,30,78,40,-3,-70};
  int N = sizeof(A) /sizeof(int);
  selectionSort(A, N);
  for (int i=0; i< N ;i++ ) {
    cout<<A[i]<<' ';
  }
  return 0;
}
