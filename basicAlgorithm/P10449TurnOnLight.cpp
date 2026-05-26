// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int MAX_STATE = 1 << 25;
short dist[MAX_STATE];//从1<<25个状态到全亮要几步

int Turn(int cur, int i)
{
    // 修改自己
    cur ^= (1 << i);

    // 上
    if (i >= 5)
    {
        cur ^= (1 << (i - 5));
    }
    // 下
    if (i < 20)
    {
        cur ^= (1 << (i + 5));
    }
    // 左
    if (i % 5 != 0)
    {
        cur ^= (1 << (i - 1));
    }
    // 右
    if (i % 5 != 4)
    {
        cur ^= (1 << (i + 1));
    }

    return cur;
}

int main()
{
    // 预处理

    memset(dist,-1,sizeof(dist));
    queue<int> q;

    int Full=(1<<25)-1;
    dist[Full]=0;
    q.push(Full);

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        int step=dist[cur];
        if(step>5)continue;
        
        for(int i=0;i<25;i++){
            int next=Turn(cur,i);
            if(dist[next]==-1){
                dist[next] = step+1;
                q.push(next);
            }
        }
    }

    int n;
    cin>>n;

    while(n--){
        int state=0;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                int t;
                scanf("%1d",&t);
                if(t==1){
                    state |= (1<<(i*5+j));
                }
            }
        }
        printf("%d\n",dist[state]);
    }
    
    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.