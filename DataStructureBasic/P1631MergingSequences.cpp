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

using Tuple = tuple<ll,int,int>;//存a[i]+b[i],i,j



int main()
{
    optimize();

    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    priority_queue<Tuple,vector<Tuple>,greater<Tuple>> pq;
    for(int i=0;i<n;i++){
        ll curSum=a[0]+b[i];
        pq.push({curSum,0,i});
    }    

    priority_queue<ll,vector<ll>,greater<ll>> Ans;

    while(Ans.size()<n && !pq.empty()){
        auto [sum,i,j]=pq.top();
        Ans.push(sum);
        pq.pop();
        pq.push({a[i+1]+b[j],i+1,j});
    }


    while(!Ans.empty()){
        cout<<Ans.top()<<' ';
        Ans.pop();
    }
    cout<<endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.