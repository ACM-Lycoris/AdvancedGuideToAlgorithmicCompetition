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

const ll INF = (1LL << 62);

int main()
{
    optimize();

    ll n, k;
    cin >> n >> k;

    vector<ll> s(n);
    vector<ll> d(n + 1);
    d[0] = INF;
    d[n] = INF;
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
        if (i > 0)
        {
            ll dist = s[i] - s[i - 1];
            d[i] = dist;
        }
    }

    vector<ll> L(n + 1), R(n + 1);
    vector<bool> del(n + 1);
    for (int i = 0; i <= n; i++)
    {
        L[i] = i - 1;
        R[i] = i + 1;
        del[i] = false;
    }
    L[0]=0;R[n]=n;//自环哨兵
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    for (ll i = 1; i <= n - 1; i++)
    {
        pq.push({d[i], i}); // dist,id
    }

    ll ans = 0;

    for (ll choose = 0; choose < k; choose++)
    {
        // 选k次为止

        while ( !pq.empty() && del[pq.top().second] )
        {
            pq.pop();
        }
        auto [dist, id] = pq.top();
        pq.pop();

        ans += dist; // 先加了再说
        if (choose == k - 1)
        {
            break;
        }

        ll regretNum = d[L[id]] + d[R[id]] - dist;
        d[id]=regretNum;
        pq.push({regretNum, id});
        del[L[id]] = true;
        del[R[id]] = true;

        L[id] = L[L[id]];
        R[id] = R[R[id]];
        R[L[id]] = id;
        L[R[id]] = id;
    }

    cout << ans << endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.