/**
* Copyright(c)
* All rights reserved
* Author: HanYang
* Date: 2018-08-04-13.02
* input: Array
* output: sorted Array
* Description: no
*/
#include<iostream>
using namespace std;

void insertionSort(int A[], int N)
{
    int i,j,x;
    for(i = 1; i< N; i++) {
        x = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > x) {
            A[j + 1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main()
{
  int A[] = { 2,7,4,0,-3,5,1}, N = sizeof(A) / sizeof(int);
  insertionSort(A, N);
  for(int i = 0; i< N; i++) {
    cout<<A[i]<<' ';
  }
  return 0;
}
