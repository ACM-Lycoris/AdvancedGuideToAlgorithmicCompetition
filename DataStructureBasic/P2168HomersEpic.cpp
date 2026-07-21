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

const ll MAXN = (1 << 62);

int main()
{
    optimize();

    ll n, k;
    cin >> n >> k;

    ll add = 0;
    while (add <= k)
    {
        if ((n + add - 1) % (k - 1) == 0)
        {
            break;
        }
        add++;
    }

    vector<ll> w(n + add + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> w[i];
    }

    for (int i = n + 1; i <= n + add; i++)
    {
        w[i] = 0;
    }

    sort(w.begin() + 1, w.end()); // 排序后自动补齐0节点

    deque<pair<ll, ll>> q; // 记录值和深度
    ll cur = 1;            // w的指针

    ll sumLen = 0;

    auto getMin = [&]() -> pair<ll, ll>
    {
        if (cur == n + add + 1 && !q.empty())
        {
            auto ans = q.front();
            q.pop_front();
            sumLen += ans.first;
            return ans;
        }
        if (cur != n + add + 1 && q.empty())
        {
            ll ans = w[cur];
            cur++;
            sumLen += ans;
            return {ans, 0};
        }
        else if (cur != n + add + 1 && !q.empty())
        {
            ll ans1 = w[cur];
            auto [ans2, deep] = q.front();
            if (ans1 <= ans2)
            {
                // 权值相同的时候，优先返回未合并的
                cur++;
                sumLen += ans1;
                return {ans1, 0};
            }
            else
            {
                sumLen += ans2;
                q.pop_front();
                return {ans2, deep};
            }
        }
    };

    ll maxDeep = 0; // 最深的合并深度，对应最长字符串

    while (cur != n + add + 1 || (cur == n + add + 1 && !q.empty()))
    {

        if (cur == n + add + 1 && q.size() == 1)
        {
            // 用完了
            break;
        }

        // 合并n-1次
        ll MergeMin = 0;
        // 每一次
        int tempK = k;
        ll nextDeep = 0;
        while (tempK--) // 严格执行k次
        {
            // 最多k次，且每次都要满足条件
            auto [curMin, deep] = getMin();

            MergeMin += curMin;
            nextDeep = max(nextDeep, deep);
        }
        nextDeep++;

        maxDeep = max(maxDeep, nextDeep);
        q.push_back({MergeMin, nextDeep});
    }

    cout << sumLen << endl;

    cout << maxDeep << endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.