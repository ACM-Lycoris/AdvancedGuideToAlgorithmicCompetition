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

    ll n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }

        vector<ll> num(n + 2);
        num[0] = 0;
        num[n + 1] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> num[i];
        }

        ll maxS = 0;
        stack<ll> stk;
        stk.push(0); // 存哨兵
        for (int i = 1; i <= n + 1; i++)
        {

            if (num[i] >= num[stk.top()])
            {
                // 增长是好事
                stk.push(i);
            }
            else
            {
                // num[i+1]<num[stk.top()];
                while (!stk.empty() && num[i] < num[stk.top()])
                {
                    
                    ll curHigh=num[stk.top()];
                    stk.pop();
                    ll curLen=i-stk.top()-1;
                    ll curS=curHigh*curLen;

                    maxS = max(curS, maxS);
                }

                stk.push(i);
            }
        }

        cout << maxS << '\n';
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.