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

    int n;
    cin>>n;
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));//dp[i][j]=dp[i-1][j]+dp[i][j-1]
    //dp[i][j]表示i个没有入栈的数个数，j为当前栈中数字个数，时，有多少种可以组成的序列
    //push对应i-1,j+1，pop对应i，j-1
    
    for(int j=0;j<=n;j++){
        dp[0][j]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){//j走不到==n的时候，
            dp[i][j]=dp[i-1][j+1];
            if(j>0){
                dp[i][j]+=dp[i][j-1];
            }
        }
    }

    cout<<dp[n][0];

    return 0;
}
  // The answer is in the depth of five fathoms. And has always been her.