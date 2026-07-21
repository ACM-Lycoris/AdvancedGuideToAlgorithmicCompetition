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

const ll BAD = INT_MAX;

int main()
{
    optimize();

    ll n,m,s;
    cin>>n>>m>>s;
    vector<vector<pair<ll,ll>>> graph(n+1);

    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        graph[u].emplace_back(v,w);
    }

    vector<ll> dist(n+1,BAD);
    dist[s]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    
    pq.push({0,s});//start

    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();

        if(dist[u]!=d){
            continue;
        }

        for(auto [v,w]:graph[u]){
            if(dist[v]>d+w){
                dist[v]=d+w;
                pq.push({dist[v],v});
            }
        }
    }

    for(ll i=1;i<=n;i++){
        cout<<dist[i]<<' ';
    }
    cout<<endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.