/**
* Copyright(c)
* All rights reserved
* Author: hy
* Date: 2018-09-26-18.08
*/
#include<iostream>
using namespace std;
// n 表示矩阵个数，count表示输入几组数据
int n;
int count=0;

/**
* @params i,j 矩阵的起始与结束
* @params s 记录了(i,j)最小数乘时的断开位置
*/
void Traceback(int i, int j, int(*s)[100])
{
    if (i==j)
    {
        cout<<"A"<<i;
        return;
    }
    // 两边不输出(
    if (i>1 || j<n)
        cout<<"(";
    // 递归遍历
    Traceback(i,s[i][j],s);
    Traceback(s[i][j]+1,j,s);
    // 两边不输出)
    if (i>1 || j<n)
        cout<<")";
}

int main()
{
    // p 数组用来存储n个矩阵的阶数
    int p[100] = {0};
    while(cin>>n)
    {
        // 表示最小数乘次数 m[i][j] 表示 第i个矩阵和第j个矩阵之间的最小数乘
        int m[100][100] = {0};
        count++;
        if(n==1)
        {
            // 考虑到只有一个矩阵时的特殊情况
            cin>>p[0]>>p[1];
            m[1][1] = p[0]*p[1];
        }
        else
        {
            for(int i=0; i<=n; i++)
            {
                cin>>p[i];
            }
        }
        // 相应的最小数乘次数对应的断开位置
        int s[100][100] = {0};
        // 从相邻矩阵的间距为2开始一个一个遍历
        for(int r=2; r<=n; r++)
        {
            // 子问题
            for(int i=1; i<=n-r+1; i++)
            {
                // 子问题
                int j = i+r-1;
                // 把[i][j] 断开为[i,i+1]和[i+1][j]
                m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
                // 记录在(i,j)间在i处断开存在最小数乘
                s[i][j]=i;
                for(int k=i+1; k<j; k++)
                {
                    // 遍历k
                    // 将[i][j]断开为[i][k]和[k+1][j]
                    int temp = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                    // 将k的遍历和第一个在i+1处断开比较
                    if(temp<m[i][j])
                    {
                        m[i][j] = temp;
                        // 记录在(i,j)间在k处断开存在最小数乘
                        s[i][j] = k;
                    }
                }
            }
        }
        cout<<"Case "<<count<<endl;
        cout<<m[1][n]<<" ";
        Traceback(1,n,s);
        cout<<endl;
    }
    return 0;
}
