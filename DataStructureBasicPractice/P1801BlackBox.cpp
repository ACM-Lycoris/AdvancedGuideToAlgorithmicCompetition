// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

inline void optimize()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    optimize();

    int m, n;
    cin >> m >> n;

    vector<ll> Box(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> Box[i];
    }
    vector<ll> Getnum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> Getnum[i];
    }

    priority_queue<ll, vector<ll>, less<ll>> pqL;
    priority_queue<ll, vector<ll>, greater<ll>> pqR;

    // 约定第i小为pqL.top();
    int k = 1; // GetNum
    ll ifGetNum = Getnum[k];
    for (int j = 1; j <= m; j++)
    {
        pqR.push(Box[j]); // 先放入右堆

        // 维护对顶堆关系
        if (!pqL.empty() && !pqR.empty() && pqL.top() > pqR.top())
        {
            ll L = pqL.top(), R = pqR.top();
            pqL.pop();
            pqR.pop();
            pqL.push(R);
            pqR.push(L);
            // 相当于交换顶
        }

        while (j == ifGetNum && !pqR.empty() && k<=n)
        {
            // 第ui个数字出现了
            ll temp = pqR.top();
            pqR.pop();
            pqL.push(temp);

            cout << pqL.top() << '\n';

            k++;
            if(k<=n){
                ifGetNum = Getnum[k];
            }else{
                break;
            }
            
        }
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.