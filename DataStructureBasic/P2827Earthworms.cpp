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

    ll n,m,q,u,v,t;
    cin>>n>>m>>q>>u>>v>>t;
    
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(all(a),greater<ll>());

    queue<ll> q1,q2,q3;

    for(ll x:a){
        q1.push(x);
    }//先都存q1

    auto getFront=[&](queue<ll> &q) -> ll{
        if(!q.empty())return q.front();
        return LLONG_MIN;
    };

    auto getMax=[&]() -> ll{
        ll x1=getFront(q1);
        ll x2=getFront(q2);
        ll x3=getFront(q3);

        if(x1>=x2 && x1>=x3){
            q1.pop();
            return x1;
        }
        if(x2>=x1&&x2>=x3){
            q2.pop();
            return x2;
        }
        q3.pop();
        return x3;
    };

    for(ll i=1;i<=m;i++){
        ll x=getMax();
        ll real=x+(i-1)*q;
        
        if(i%t==0){
            cout<<real<<' ';
        }

        ll left=real*u/v;
        ll right=real-left;

        q2.push(left - i*q);
        q3.push(right-i*q);

    }

    cout<<endl;

    for(int i=1;i<=(n+m);i++){
        ll x= getMax();
        ll real=x+m*q;

        if(i%t==0){
            cout<<real<<' ';
        }
    }
    cout<<endl;



    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.