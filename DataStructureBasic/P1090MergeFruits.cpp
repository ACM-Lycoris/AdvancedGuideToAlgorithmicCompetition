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

    ll n;
    cin>>n;

    priority_queue<ll,vector<ll>,greater<ll>> pq;//小根堆

    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        pq.push(x);
    }

    ll ans=0;
    while(!pq.empty()){
        ll a=pq.top();
        pq.pop();
        
        if(!pq.empty()){
            ll b=pq.top();
            pq.pop();
            ll sum=a+b;
            ans+=sum;
            pq.push(sum);
        }else{
            break;//只剩最后一个了
        }
    }

    cout<<ans<<endl;


    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.