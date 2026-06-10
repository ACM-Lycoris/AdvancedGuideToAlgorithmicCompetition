#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using tp = tuple<ll,ll,ll>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;

    vector<pll> arr(n+1);
    for(ll i=0;i<=n;i++){
        cin>>arr[i].first>>arr[i].second;
    }

    sort(arr.begin()+1,arr.end(),[&](const pll &a,const pll &b){
        ll mulA=a.first*a.second;
        ll mulB=b.first*b.second;

        return mulA<mulB;

    });
    

    ll maxRes  = arr[0].first;
    ll leftPAI = arr[0].first;
    for(auto [l,r]:arr){
        ll curRes=leftPAI/r;
        leftPAI*=l;
        maxRes=max(maxRes,curRes);
    }

    cout<<maxRes<<'\n';
    
    return 0;
}