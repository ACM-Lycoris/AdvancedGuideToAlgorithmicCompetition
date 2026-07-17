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
    while (cin >> n)
    {

        vector<pair<ll, ll>> Prod(n);
        for (int i = 0; i < n; i++)
        {
            cin >> Prod[i].first >> Prod[i].second;
            // 利润和截止时间
        }

        sort(all(Prod), [&](const pair<ll, ll> &a, const pair<ll, ll> &b)
             { return a.second < b.second; });

        ll maxMoney = 0;
        // 排好序后
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 0; i < n; i++)
        {

            auto [p, d] = Prod[i];
            pq.push(p);
            maxMoney += p;
            if (pq.size() > d)
            {
                maxMoney -= pq.top();
                pq.pop();
            }
        }

        cout << maxMoney << '\n';
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.