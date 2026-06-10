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
    vector<tp> cows(n);

    for(ll i=0;i<n;i++){
        ll l,r;
        cin>>l>>r;
        cows[i] = {l,r,i};
    }
    sort(cows.begin(),cows.end(),[&](const tp &a,const tp &b){
        ll t1=get<0>(a),t2=get<0>(b);
        return t1<t2;
    });

    vector<ll> ans(n);

    priority_queue<pll,vector<pll>,greater<pll>> pq;//存入该牛棚的结束时间和棚子id

    ll resCnt=0;//已经用过的牛棚数量

    for(ll i=0;i<n;i++){
        auto [l,r,id] = cows[i];
        if(!pq.empty() && pq.top().first<l){//上一头牛挤奶时间已经结束了，重新用这个棚子
            ll idx=pq.top().second;
            pq.pop();
            ans[id]=idx;//第id个给这个棚子了
            pq.push({r,idx});
        }else{
            resCnt++;
            ans[id]=resCnt;
            pq.push({r,resCnt});
        }
    }

    cout<<resCnt<<endl;
    for(int num:ans){
        cout<<num<<endl;
    }
    return 0;
}