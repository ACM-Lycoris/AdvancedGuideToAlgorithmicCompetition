// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin>>n>>m;

    vector<pair<ll,ll>> ops(n);
    for(ll i=0;i<n;i++){
        string op;
        cin>>op>>ops[i].second;
        if(op=="AND"){
            ops[i].first=0;
        }else if(op=="OR"){
            ops[i].first=1;
        }else{
            ops[i].first=2;
        }
    }

    ll val0=0;
    ll val1=(1<<30)-1;

    for(int i=0;i<n;i++){
        ll cur=ops[i].second;
        if(ops[i].first==0){
            val0&=cur;
            val1&=cur;
        }else if(ops[i].first==1){
            val0|=cur;
            val1|=cur;
        }else{
            val0^=cur;
            val1^=cur;
        }
    }

    ll cur=0,ans=0;

    for(int i=29;i>=0;i--){
        if((val0>>i)&1){
            //如果选0，结果就是1
            //答案直接取1或就行
            ans|=(1<<i);
        }else if((val1>>i)&1){
            //选1得考虑是否超出m
            if((cur|(1<<i))>m){
                continue;
            }else{
                cur|=(1<<i);
                ans|=(1<<i);
            }

        }
    }

    cout<<ans<<endl;
    
    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.