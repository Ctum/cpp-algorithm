#include <bits/stdc++.h>
using namespace std;
const int maxn=100;
typedef long long ll;
int  n;
struct Point
{
    int val,id;
    vector<int> sta;
    bool operator < (const Point & b) const 
    {
        if(val==b.val) return id < b.id;
        return val>b.val;
    }
}ans[maxn];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int T;
    int Case=0;
    cin>>T;
    while(T--)
    {
        scanf("%d",&n);
        string ret[maxn];
        priority_queue<Point> que;
        for(int i=1;i<=n;i++)
        {
            int w;
            Point tmp;
            scanf("%d",&w);
            ans[i].val=w;
			tmp.val=w;
            tmp.id=i;
            tmp.sta.push_back(i);
            que.push(tmp);
        }
        int num=n;
        while(que.empty()==0)
        {
            Point right=que.top();
            que.pop();
            if(que.empty()) break;
            Point left=que.top();
            que.pop();
            Point tmp;
            tmp.id=++num;
            tmp.val=right.val+left.val;
            tmp.sta.clear();
            for(int i=0;i<right.sta.size();i++)
            {
                int id=right.sta[i];
                ret[id].push_back('1');
                tmp.sta.push_back(id);
            }
            for(int i=0;i<left.sta.size();i++)
            {
                int id=left.sta[i];
                ret[id].push_back('0');
                tmp.sta.push_back(id);
            }
            que.push(tmp);
        }
        printf("Case %d\n",++Case);
        for(int i=1;i<=n;i++)
        {
            reverse(ret[i].begin(),ret[i].end());
            cout<<ans[i].val<<" "<<ret[i]<<endl;
        }
        cout<<endl;
    }
    return 0;
}