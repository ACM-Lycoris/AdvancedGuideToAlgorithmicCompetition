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

    ll n,k;
    cin>>n>>k;

    vector<ll> a(n+1);

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    deque<ll> q1,q2;//最小与最大
    vector<ll> mins,maxs;

    for(int i=1;i<=n;i++){
        while(!q1.empty() && (a[q1.back()])>=a[i]){
            q1.pop_back();
        }
        while(!q2.empty() && (a[q2.back()])<=a[i]){
            q2.pop_back();
        }//维护单调

        q1.push_back(i);
        q2.push_back(i);

        //维护长度
        while(!q1.empty() && (q1.front()<=i-k)){
            q1.pop_front();
        }
        while(!q2.empty() && (q2.front()<=i-k)){
            q2.pop_front();
        }

        if(i>=k){
            mins.emplace_back(a[q1.front()]);
            maxs.emplace_back(a[q2.front()]);
        }
    }

    for(int num:mins){
        cout<<num<<' ';

    }

    cout<<endl;
    for(int num:maxs){
        cout<<num<<' ';
    }

    cout<<endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.