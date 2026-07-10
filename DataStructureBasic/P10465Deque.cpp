// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;cin>>n;
    vector<pair<ll,ll>> a(n);
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        a[i-1]={x,i};
    }

    sort(all(a));

    vector<pair<ll,ll>> range;
    //range存放每个数字第一次和最后一次出现的下标
    
    for(int i=0;i<n;){
        
        ll L=a[i].second;
        ll R=a[i].second;
        ll j=i;
        while (j<n && a[i].first==a[j].first)
        {
            
            L=min(L,a[j].second);
            R=max(R,a[j].second);
            j++;
        }
        range.emplace_back(L,R);
        i=j;
    }

    ll last=n+5;
    bool up=false;

    ll ans=1;

    for(auto [L,R]:range){
        
        if(!up){
            if(R<=last){
                last=L;
            }else{
                up=true;
                last=R;//进入上升阶段
            }
        }else{
            if(L>=last){
                last=R;
            }else{
                up=false;
                last=L;
                ans++;
            }
        }

    }

    cout<<ans<<endl;

    
    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.