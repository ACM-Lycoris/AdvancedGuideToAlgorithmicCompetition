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

ll n, w;

int main()
{
    optimize();

    cin >> n >> w;
    vector<ll> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    sort(c.rbegin(), c.rend());

    ll ans = n;//明确上界剪枝

    vector<ll> Cars(20, 0); // 每个缆车的目前承载重量

    auto DFS = [&](auto &&self, int u, int cnt)
    {
        // 捕获当前准备处理第几只猫和使用的缆车的数量

        if (cnt >= ans)
        {
            return;
        }
        if (u == n)
        { /// 安排从0开始，所以等于n判定结束
            ans = cnt;
            return;
        }

        set<ll> curLoad; // 当前层的载重

        for (int i = 0; i < cnt; i++)
        {
            if (Cars[i] + c[u] > w)
            {
                continue;
            }
            if (curLoad.count(Cars[i]))
            {
                continue;
            }
            curLoad.insert(Cars[i]);
            Cars[i] += c[u];
            self(self, u + 1, cnt);
            Cars[i] -= c[u];
        }

        // 尝试装新车
        Cars[cnt] = c[u];
        self(self, u + 1, cnt + 1);
        Cars[cnt] = 0;
    };

    DFS(DFS, 0, 0);

    cout << ans << endl;

    return 0;
}