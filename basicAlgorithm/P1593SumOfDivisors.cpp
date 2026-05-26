// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

inline void optimizeIO(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const int MOD = 9901;

ll qpow(ll a,ll b)
{
    ll res=1;
    a%=MOD;

    while(b){
        if(b&1){
            res=res*a%MOD;
        }
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

ll sum(ll p,ll c){//p1,p2是不同的质因子,c1,c2是他们出现的次数

    if(c==0){
        return 1;
    }
    if(c==1){
        return (1+p)%MOD;
    }

    if(c&1){
        return (sum(p,c/2)*(1+qpow(p,c/2+1)))%MOD;
    }else{
        return (sum(p,c-1)+qpow(p,c))%MOD;
    }

}

int main()
{
    optimizeIO();

    ll a,b;
    cin>>a>>b;
    //分解因数
    ll ans =1;

    for(ll i=2;i*i<=a;i++){
        if(a%i==0){
            ll cnt=0;
            while(a%i==0){
                a/=i;
                cnt++;
            }
            ans=ans*sum(i,cnt*b)%MOD;
        }
    }    
    
    if(a>1){
        ans = ans * sum(a,b) %MOD;
    }

    cout<<ans%MOD<<endl;;
    
    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.
