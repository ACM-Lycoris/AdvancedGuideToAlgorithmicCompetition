// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

vector<int> tree;

int m;

void add(int x,int val){
    //在x处val
    while(x<=m){
        tree[x]+=val;
        x+=x&-x;
    }
}

//int query(){
//}

int Kth(int k){
    //在tree中第k小的数字，这里要用倍增

    int pos = 0;
    int cnt = 0;

    int step=1;
    while((step<<1)<=m){
        //找到最大步长
        step<<=1;
    }

    for(;step>0;step>>=1){
        if(pos+step<=m && cnt+tree[pos+step]<k){
            pos+=step;
            cnt+=tree[pos];
        }
    }
    return pos+1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> nums=a;
    sort(all(nums));

    nums.erase(unique(all(nums)),nums.end());
    m=nums.size();
    vector<int>Ids(m);
    tree.assign(m+1,0);
    for(int i=0;i<n;i++){
        int rank = lower_bound(all(nums),a[i])-nums.begin()+1;
        //这个数字在离散组的第几个
        add(rank,1);//然后tree频率对应位置+1

        int curCnt=i+1;//当前已经插入了的元素数量

        if(curCnt & 1){
            int k=(curCnt+1)/2;//第k小
            int medianRank = Kth(k);//的数字是第几个

            int Median = nums[medianRank-1];//Kth是1-based
            cout<<Median<<'\n';

        }

    }   
    
    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.