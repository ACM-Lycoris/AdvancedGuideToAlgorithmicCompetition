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

    int n;
    cin>>n;
    vector<pair<ll,ll>> cows(n);
    for(int i=0;i<n;i++){
        cin>>cows[i].first>>cows[i].second;
        //体重和力量
    }

    sort(all(cows),[&](const pair<ll,ll> &a,const pair<ll,ll> &b){
        return a.first+a.second < b.first+b.second;
    });

    ll sum=0;ll ans=LLONG_MIN;

    for(ll i=0;i<n;i++){
        ans=max(ans,sum-cows[i].second);
        sum+=cows[i].first;
    }
    cout<<ans<<endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.