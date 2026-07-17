// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> T(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> T[i].first >> T[i].second;
    }

    ll cnt = 0;
    ll curCostTime = 0; // 当前花费时间
    priority_queue<ll, vector<ll>, less<ll>> pq;

    sort(all(T), [&](const pair<ll, ll> &a, const pair<ll, ll> &b)
         { return a.second < b.second; });

    for (ll i = 0; i < n; i++)
    {
        auto [T1, T2] = T[i];
        // 修复时间和报废时间

        // 修理当前这一个
        cnt++;
        curCostTime += T1;
        pq.push(T1);

        while (curCostTime > T2)
        {
            curCostTime -= pq.top();
            pq.pop();
            cnt--;
        }
    }

    cout << cnt << endl;
    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.