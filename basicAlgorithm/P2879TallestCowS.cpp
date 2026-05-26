// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

inline void optimizeIO(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    optimizeIO();

    ll N,I,H,R;
    cin>>N>>I>>H>>R;

    vector<ll> diff(N+1,0);
    map<pair<ll,ll>,bool> mp;
    while(R--){
        ll a,b;
        cin>>a>>b;
        
        if(!mp[{min(a,b),max(a,b)}]){
            diff[min(a,b)+1]--;
            diff[max(a,b)]++;
            mp[{min(a,b),max(a,b)}]=true;//666每组数据可能重复出现，因为a看到b，b也看到a，应视为同一组数据
            //所以只需要处理第一次出现就行
            //臭阴
            
        }
    }

    vector<ll> Ori(N+1,0);
    Ori[I]=H;//最高的山
    //分别向前向后还原数组
    for(int i=I+1;i<=N;i++){
        Ori[i]=diff[i]+Ori[i-1];
    }            
    for(int i=I-1;i>=1;i--){
        Ori[i]=Ori[i+1]-diff[i+1];
    }

    for(int i=1;i<=N;i++){
        cout<<Ori[i]<<'\n';
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.
