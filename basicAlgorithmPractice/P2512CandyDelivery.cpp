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

    ll n;
    cin>>n;

    vector<ll> a(n);
    vector<ll> Diff(n);//残差数组
    vector<ll> Pref(n,0);//前缀残差

    ll avg=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        avg+=a[i];
    }
    avg/=n;

    for(int i=0;i<n;i++){
        Diff[i]=avg-a[i];
    }

    for(int i=1;i<n;i++){
        Pref[i]=Pref[i-1]+Diff[i-1];
    }

    sort(all(Pref));

    ll mid=Pref[n/2];

    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=(abs(Pref[i]-mid));
    }

    cout<<ans<<endl;
    
    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.