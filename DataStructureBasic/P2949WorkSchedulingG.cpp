// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;
    vector<pair<ll,ll>> Works(n);
    for(int i=0;i<n;i++){
        cin>>Works[i].first>>Works[i].second;
    }
    
    sort(all(Works),[&](const pair<ll,ll> &a,const pair<ll,ll> &b){
        return a.first<b.first;
    });

    priority_queue<ll,vector<ll>,greater<ll>> pq;
    ll ans=0;
    for(ll i=0;i<n;i++){
        auto [D,P]=Works[i];
        pq.push(P);
        ans+=P;

        if(pq.size()>D){
            ans-=pq.top();
            pq.pop();
        }

    }
    cout<<ans<<endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.