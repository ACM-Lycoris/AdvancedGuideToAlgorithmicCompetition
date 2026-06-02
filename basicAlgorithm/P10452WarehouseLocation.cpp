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

    int n;
    cin>>n;
    vector<int> pos(n);
    for(int i=0;i<n;i++){
        cin>>pos[i];
    }

    sort(pos.begin(),pos.end());
    
    ll bestPos=-1;
    if(n&1){
        bestPos=pos[(n+1)/2];
    }else{
        bestPos=pos[n/2];
    }

    int ans=0;
    for(int num:pos){
        ans+=abs(num-bestPos);
    }
  
    cout<<ans<<endl;
    
    
    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.