#include<iostream>
using namespace std;

template <class T>
int getLen(T &arr) {
  return (sizeof(arr) / sizeof(arr[0]));
}
// 给函数传递数组的三种方式:1.(int *param), 2.(int param[10]), 3.(int param[])
void mergeArr(int *A,int *B,int *result,int aLen, int bLen)
{
    int s = 0, t = 0;
    int k = 0;
    while(s <= aLen -1 && t<= bLen -1) {
        if (A [s] <= B[t]) {
           result[k++] = A[s++];
        } else {
           result[k++] = B[t++];
        }
    }
    if (s == aLen){
        for(int i= t; i <= bLen -1; i++) {
            result[k++] = B[i];
        }
    } else {
        for(int i= s; i <= aLen -1; i++) {
            result[k++] = A[i];
        }
    }
}

int main()
{
    int A[] = {-1, 3,7,9,10};
    int B[] = {-5, -3, 3, 6, 11, 23, 67, 90};
    int result[100];
    mergeArr(A, B, result, getLen(A), getLen(B));
    for(int i = 0; i< getLen(A) + getLen(B); i++) {
        cout<<result[i]<<' ';
    }
    return 0;
}
