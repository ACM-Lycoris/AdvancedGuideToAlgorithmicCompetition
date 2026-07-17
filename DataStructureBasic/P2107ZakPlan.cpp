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

    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());

    ll cnt = 0;
    ll curCostTime = 0;
    priority_queue<ll, vector<ll>, less<ll>> pq;
    ll j = n - 1; // 当前最远距离指针，也就是走路要花多久
    ll ans = 0;
    for (auto [x, t] : a)
    {
        // x从大往小算的
        curCostTime += t;
        pq.push(t);
        cnt++;
        while (!pq.empty() && x + curCostTime > m)
        {
            curCostTime -= pq.top();
            cnt--;
            pq.pop();
        }
        // 答案可能先大后小地变，维护最大值
        ans = max(cnt, ans);
    }

    cout << ans << endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.