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

    int n,m;
    cin>>n>>m;

    vector<vector<int>>graph (5010,vector<int>(5010,0));
    vector<vector<int>> pref (5010,vector<int>(5010,0));

    while(n--){
        int i,j,v;
        cin>>i>>j>>v;
        i++;j++;//转换成1based
        graph[i][j]+=v;//可能有多个目标在同一个点的情况，不能graph[i][j]=v
        
    }

    for(int i=1;i<=5001;i++){
        for(int j=1;j<=5001;j++){
            pref[i][j]=graph[i][j]+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
        }
    }

    ll bestSum=LLONG_MIN;
    
    for(int i=m;i<=5001;i++){
        for(int j=m;j<=5001;j++){
            ll curSum=pref[i][j]-pref[i-m][j]-pref[i][j-m]+pref[i-m][j-m];
            bestSum=max(bestSum,curSum);
        }
    }

    cout<<bestSum<<endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.
