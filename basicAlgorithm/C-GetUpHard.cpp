#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //链接LibreOJ2244
    //https://loj.ac/p/2244

    ll n,m;
    cin>>n>>m;

    vector<pair<int,ll>> Doors(n);
    for(int i=0;i<n;i++){
        string op;
        cin>>op>>Doors[i].second;
        if(op=="AND"){
            Doors[i].first=0;
        }else if(op=="OR"){
            Doors[i].first=1;
        }else{
            Doors[i].first=2;
        }
    }

    //所有情况涵盖从0到1<<m，位运算贪心就能解决
    int val0=0;
    int val1=(1<<30)-1;//到2^30-1

    //用两个极端值算出每种情况应该填0还是1（我们希望最后1尽可能多）

    for(int i=0;i<n;i++){
        if(Doors[i].first==0){
            val0&=Doors[i].second;
            val1&=Doors[i].second;
        }else if(Doors[i].first==1){
            val0|=Doors[i].second;
            val1|=Doors[i].second;
        }else{
            val0^=Doors[i].second;
            val1^=Doors[i].second;
        }
    }
    

    ll ans=0,cur=0;
    for(int i=29;i>=0;i--){
        if((val0>>i)&1){
            //填0,结果成1，cur还是0
            ans|=(1<<i);
        }else if((val1>>i)&1){
            //填1，结果还是1
            //考虑填1是否超出m

            if((cur|(1<<i))<=m){
                //不超出m就填1

                cur|=(1<<i);
                ans|=(1<<i);

            }
        }
    }

    cout<<ans<<endl;

    return 0;
}