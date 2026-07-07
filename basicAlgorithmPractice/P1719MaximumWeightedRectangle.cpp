// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    // vector<vector<int>> graph(n,vector<int>(n,0));
    vector<vector<int>> prefC(n + 1, vector<int>(n + 1, 0)); // 列前缀和
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int num;
            cin >> num;
            prefC[i][j] = prefC[i - 1][j] + num;
        }
    }

    int best=INT_MIN;
    for (int top = 1; top <= n; top++)
    {
        for (int bot = top; bot <= n; bot++)
        {
            //枚举上下两界
            //对界内列之和做一个Kadane
            int cur=0;
            for(int i=1;i<=n;i++){
                int aj=prefC[bot][i]-prefC[top-1][i];
                cur=max(aj,cur+aj);
                best=max(cur,best);
            }
        }
    }

    cout<<best<<endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.