/**
* Copyright(c)
* All rights reserved
* Author: hy
* Date: 2018-10-24-18.13
*/
#include<iostream>
#include<string>
using namespace std;

const int MAX_N = 100; // max容量
const int INF = 65535;

class HNode
{
public:
    double weight;
    int parent;
    int lchild;
    int rchild;
    int id;;
};

class HuffCode
{
public:
    string code;
    double weight;
};

class Huffman
{
public:
    Huffman(){}
    ~Huffman(){}

    void createForest(double *arr, int length)
    {
        // 初始化节点
        sum = length;
        for(int i = 0;i < sum;i++) {
            ht[i].weight = arr[i];
            ht[i].id = i;
        }
    }

    void createHuffmanTree()
    {
        int lnode, rnode, id;
        double min1, min2;
        for(int i=0;i<sum;i++) {
            ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
        }
        for(int j=sum;j<2*sum-1;j++) {
            min1 = min2 = INF;
            lnode = -1;
            rnode = -1;
            for(int k=0; k<j;k++) {
                if (ht[k].parent == -1) {
                    if(ht[k].weight < min1) {
                        min2 = min1;//最小赋值给次小
						rnode = lnode;//同理下标
						min1 = ht[k].weight;//新的最小频率值
						id = ht[k].id;
						lnode = k;//其下标
                    }
                    else if (ht[k].weight == min1) {
                        if (ht[k].weight < id) {
                            min2 = min1;//最小赋值给次小
                            rnode = lnode;//同理下标
                            min1 = ht[k].weight;//新的最小频率值
                            id = ht[k].id;
                            lnode = k;//其下标
                        }
                    }
                    else if (ht[k].weight < min2) {
                        min2 = ht[k].weight;
						rnode = k;
                    }
                    if (ht[k].weight < min1)//小于最小
					{
					    // 左子树
						min2 = min1;//最小赋值给次小
						rnode = lnode;//同理下标
						min1 = ht[k].weight;//新的最小频率值
						lnode = k;//其下标
					}//end if -> less

					//不小于最小，小于次小
					else if (ht[k].weight < min2)
					{
						min2 = ht[k].weight;
						rnode = k;
					}

                }
            }
            // 构造 j 这个父节点
            ht[j].weight = ht[lnode].weight + ht[rnode].weight;//双亲结点权重
            ht[j].lchild = lnode;//双亲节点左孩子
            ht[j].rchild = rnode;
            ht[j].id = j;
            ht[lnode].parent = j;//原最小频率值所在节点的双亲节点赋值为当前节点j
            ht[rnode].parent = j;
            ht[j].parent = -1;
        }
    }

    bool createHuffCode()
    {
        int f, c;
		HuffCode hc;
		for (int i = 0; i < sum; i++)//作为hcode下标
		{
			c = i;//下标->左节点
			f = ht[i].parent;
			while (f != -1)//未到根节点
			{
				if (ht[f].lchild == c)//找到左节点
				{
					hc.code.assign("0" + hc.code);//左边较小赋值为0

				}//end if -> left node

				else
				{
					hc.code.assign("1" + hc.code);//右边赋值为1
				}//end else -> right node

				c = f;//替换为上一层节点
				f = ht[f].parent;//上一层的双亲节点
			}//end while

			hcode[i] = hc;//赋值当前编码
			hc.code.clear();//清空code内容，进行下一次访问
		}//end for

		return true;
    }

    void display()
	{
		for (int i = 0; i < sum; i++)
		{
			cout << ht[i].weight << ":";//被编码数据
			cout << hcode[i].code << endl;//编码
		}//end for
	}

private:
    HNode ht[MAX_N]; // 原始节点
    HuffCode hcode[MAX_N];  // 编码数据
    int sum;    // 总节点数
};

int main()
{
  Huffman huff;
  double arr[6] = {9,8,3,4,2,1};
  huff.createForest(arr, 6);
  huff.createHuffmanTree();
  huff.createHuffCode();
  huff.display();
  return 0;
}
