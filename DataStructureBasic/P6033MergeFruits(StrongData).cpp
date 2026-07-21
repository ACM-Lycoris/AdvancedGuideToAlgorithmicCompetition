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

const int MAXN = 1e5 + 10;
ll cnt[MAXN];
int main()
{
    optimize();

    ll n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    deque<ll> q; // 双端队列

    ll cur = 0; // 当前未合并的最小值

    auto getMin = [&]() -> ll
    {
        // cur 向右找到当前仍然存在的最小原始果堆
        while (cur < MAXN && cnt[cur] == 0)
        {
            cur++;
        }

        // 原始果堆已经全部取完
        if (cur >= MAXN)
        {
            ll ans = q.front();
            q.pop_front();
            return ans;
        }

        // 合并队列还是空的，只能取原始果堆
        if (q.empty())
        {
            cnt[cur]--;
            return cur;
        }

        // 两个有序队列队头比较
        if (cur <= q.front())
        {
            cnt[cur]--;
            return cur;
        }
        else
        {
            ll ans = q.front();
            q.pop_front();
            return ans;
        }
    };

    ll result = 0;

    n--;
    while (n--)
    {
        ll a = getMin();
        ll b = getMin();

        result += (a + b);
        q.push_back(a + b);
    }

    cout << result << '\n';

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.