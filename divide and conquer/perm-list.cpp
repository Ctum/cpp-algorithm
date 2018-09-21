/**
* Copyright(c)
* All rights reserved
* Author: hy
* Date: 2018-09-21-18.46
*/
#include<iostream>
using namespace std;

template<class Type>
inline void Swap(Type &a, Type &b)
{
    Type temp = a;
    a = b;
    b = temp;
}

/**
* 产生从k:m的所有排列
*/
template<class Type>
void Perm(Type list[], int k, int m)
{
    if(k == m) {
        for (int i =0; i<=m;i++) cout<<list[i];
        cout<<endl;
    } else {
        for(int i = k;i<=m;i++) {
            Swap(list[k], list[i]);
            Perm(list, k+1, m);
            Swap(list[k],list[i]);
        }
    }
}

int main()
{
  int testList[] = {1,2,3,4,5};
  Perm(testList, 0,4);
  return 0;
}
