// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ull = unsigned long long;

inline void optimizeIO()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    optimizeIO();

    ll n;
    cin>>n;
    vector<ll> Languages(n);
    unordered_map<ll,ll> Cnts;//得按照愉悦度最多的排序
    for(int i=0;i<n;i++){
        cin>>Languages[i];
        Cnts[Languages[i]]++;
    }

    ll m;
    cin>>m;
    
    vector<pair<ll,ll>> Voices(m);
    map<pair<ll,ll>,int> Ids;//每一个pair对应的编号
    for(int i=0;i<m;i++){
        cin>>Voices[i].first;
    } 
    for(int i=0;i<m;i++){
        cin>>Voices[i].second;
        Ids[Voices[i]]=i+1;
    }

    sort(Voices.begin(),Voices.end(),[&](const pair<ll,ll> &a,const pair<ll,ll> &b){
        ll VoiA=Cnts[a.first],textA=Cnts[a.second];
        ll VoiB=Cnts[b.first],textB=Cnts[b.second];
        //配音 和 字幕

        if(VoiA!=VoiB){
            return VoiA>VoiB;
        }else{
            return textA>textB;
        }
    });

    cout<<Ids[Voices[0]]<<endl;
    
    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.