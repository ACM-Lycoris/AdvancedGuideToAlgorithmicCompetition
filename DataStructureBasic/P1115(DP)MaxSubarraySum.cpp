// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

inline void optimizeIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    optimizeIO();

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    vector<int> dp(n);

    dp[0]=a[0];
    int bestAns=dp[0];
    for(int i=1;i<n;i++){

        dp[i]=max(dp[i-1]+a[i],a[i]);
        bestAns=max(dp[i],bestAns);
    }

    cout<<bestAns<<endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.