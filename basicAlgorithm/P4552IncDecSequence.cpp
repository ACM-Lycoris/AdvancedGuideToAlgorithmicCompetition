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

    int n;
    cin>>n;
    vector<ll> nums(n+1,0);

    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    vector<ll> diff(n+2,0);
    diff[1]=nums[1];

    ll sumPos=0,sumNegABS=0;
    for(int i=2;i<=n;i++){
        diff[i]=nums[i]-nums[i-1];
        if(diff[i]>0){
            sumPos+=diff[i];
        }else if(diff[i]<0){
            sumNegABS+=abs(diff[i]);
        }
    }

    ll minOp=min(sumPos,sumNegABS)+abs(sumPos-sumNegABS);//最小操作次数
    ll maxPerm=abs(sumNegABS-sumPos)+1;

    cout<<minOp<<"\n"<<maxPerm<<"\n";

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.
