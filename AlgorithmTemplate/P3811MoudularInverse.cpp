// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

ll qpow (ll a,ll b ,ll p){
    a%=p;
    ll ans=1;
    while(b>0){
        if(b&1){
            ans=(ans*a)%p;
        }
        a=a*a%p;
        b>>=1;
    }
    return ans;
}
ll inv[3000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,p;
    scanf("%lld%lld",&n,&p);

    
    inv[1]=1;
    printf("%lld\n",1);
    for(ll i=2;i<=n;i++){
        inv[i]=(-1*(p/i)*inv[p%i]%p+p)%p;
        printf("%lld\n",inv[i]);
    }
    

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.