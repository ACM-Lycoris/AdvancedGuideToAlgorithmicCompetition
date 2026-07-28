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

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    auto check = [&](const ll &M) -> bool
    {
        // 检查当前侧站容量能否可行
        ll len = M + 1; // 代表当前可选范围
        ll cost = 0;    // 花了多少备用宝石
        ll cntZreo = 0; // 窗口内的0的个数

        priority_queue<ll, vector<ll>, less<ll>> window; // 当前窗口内的
        priority_queue<ll, vector<ll>, less<ll>> all;    // 全局最大值
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > 0)
                all.push(a[i]);
        }

        for (ll i = 1; i <= len && i <= n; i++)
        {
            ll id = n - i + 1;
            if (a[id] == 0)
            {
                cntZreo++; // 放入0就加0的个数
            }
            else
            {
                window.push(a[id]);
            }
        }

        ll id = n - M - 1; // 下一个要放入窗口的数

        while (!all.empty())
        {
            if (!window.empty() && window.top() == all.top())
            {
                // 全局最大就在当前窗口
                // 填入栈内
                all.pop();
                window.pop();
            }
            else
            {
                if (cntZreo > 0)
                {
                    // 尝试给空矿车填入这个最大值
                    cost += (all.top());
                    if (cost > k)
                    {
                        // 用多了
                        return false;
                    }
                    cntZreo--;
                }
                else
                {
                    // 挂了
                    return false;
                }
            }

            if (id >= 1)
            {
                if (a[id] == 0)
                {
                    cntZreo++;
                }
                else
                {
                    window.push(a[id]);
                }
                id--;
            }
        }

        // 能走到这
        return true;
    };

    ll l = 0, r = n - 1;

    while (l < r)
    {
        ll mid = l + (r - l) / 2;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.