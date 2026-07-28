// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

inline void optimize()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    optimize();

    ll n,m,q;
    cin>>n>>m>>q;
    string a,b;
    cin>>a>>b;
    a=" "+a;b=" "+b;

    vector<ll> z(m+1);
    z[1]=m;
    for(ll i=2,L=1,R=1;i<=m;i++){
        if(i<=R){z[i]=min(R-i+1,z[i-L+1]);
        }
        while(i+z[i]<=m && b[i+z[i]]== b[1+z[i]]){
            z[i]++;
        }
        if(i+z[i]-1>R){
            R=i+z[i]-1;
            L=i;
        }
    }

    vector<ll> p(n+1);
    //对a的扩展数组

    for(ll i=1,L=1,R=0;i<=n;i++){
        if(i<=R){
            p[i]=min(R-i+1,z[i-L+1]);
        }
        while (i+p[i]<=n && 1+p[i]<=m && a[i+p[i]]==b[1+p[i]]){
            p[i]++;
        }
        if(i+p[i]-1>R){
            R=i+p[i]-1;
            L=i;
        }
    }

    unordered_map<ll,ll> mp;//匹配长度为x的个数
    for(int i=1;i<=n;i++){
        ll x=p[i];
        mp[x]++;
    }

    while(q--){
        ll queryX;cin>>queryX;
        if(mp.count(queryX)){
            cout<<mp[queryX]<<'\n';
        }else{
            cout<<0<<'\n';
        }
    }
    cout<<endl;


    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.