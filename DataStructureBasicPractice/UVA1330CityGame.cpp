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

    int T;
    cin >> T;
    int n, m;
    vector<vector<ll>> Graph; // 存图
    vector<vector<ll>> Temp;  // 中间图量

    while (T--)
    {

        cin >> n >> m;
        Graph.assign(n + 1, vector<ll>(m + 1, 0));
        Temp.assign(n + 1, vector<ll>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char c;
                cin >> c;
                Graph[i][j] = (c == 'R' ? 1 : 0);
            }
        }

        ll maxArea = 0;

        // 枚举每一行作为底，每一个位置上方空格高度为高，再维护单调栈，时刻计算最大空白面积

        for (int i = 1; i <= n; i++)
        {
            // 每一行
            vector<ll> curCol(m + 2, 0);
            for (int j = 1; j <= m; j++)
            {
                if (Graph[i][j] == 1)
                {
                    curCol[j] = 0;
                    Temp[i][j] = 0;
                }
                else
                {
                    curCol[j] = Temp[i - 1][j] + 1;
                    Temp[i][j] = Temp[i - 1][j] + 1;
                }
            }

            // 用当前行维护一个单调栈
            stack<ll> stk;
            stk.push(0);

            for (int j = 1; j <= m + 1; j++)
            {

                while (!stk.empty() && curCol[j] < curCol[stk.top()])
                {
                    ll curHigh = curCol[stk.top()];
                    stk.pop();
                    ll curLen = j - stk.top() - 1;
                    ll curArea = curLen * curHigh;
                    maxArea = max(maxArea, curArea);
                }
                stk.push(j);
            }
        }

        cout << maxArea * 3 << '\n';
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.