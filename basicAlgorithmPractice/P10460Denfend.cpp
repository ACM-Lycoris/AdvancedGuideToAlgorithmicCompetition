// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
inline void optimize()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

using ll = long long;

const string Safe = "There's no weakness.";

struct Node{
    ll s,e,d;
};

vector<Node> Def;

ll prefCnt(ll x){
    //坐标x往前有多少个防具
    ll ans=0;

    for(auto &p:Def){
        if(x<p.s){
            continue;
        }
        ll r=min(x,p.e);
        ans+=((r-p.s)/p.d+1);
    }
    return ans;
}

ll cntX(ll x){
    //坐标x处有多少防具
    ll ans=0;
    for(auto &p:Def){
        if(p.s<=x && x<=p.e && ((x-p.s)%p.d==0)){
            ans++;
        }
    }
    return ans;
}

int main() 
{
    optimize();
    
    ll T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;

        Def.assign(n,{0,0,0});
        
        ll r=INT_MIN,l=INT_MAX;

        for(int i=0;i<n;i++){
            cin>>Def[i].s>>Def[i].e>>Def[i].d;
            l=min(Def[i].s,l);
            r=max(Def[i].e,r);
        }

        if(prefCnt(r)%2==0){
            cout<<Safe<<endl;
            continue;
        }
        //cout<<l<<' '<<r<<endl;
        while(l<r){
            ll mid=l+(r-l)/2;
            //cout<<mid<<' ';
            if(prefCnt(mid)&1){
                //奇数，缩右边界
                r=mid;
            }else{
                l=mid+1;
            }
        }
        //cout<<endl;
        ll ansP=l;
        ll ansC=cntX(l);

        cout<<ansP<<' '<<ansC<<'\n';
        

    }

    return 0;
}

// The answer is in the depth of five fathoms. And has always been her.