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

    vector<ll> num(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }

    vector<ll> Maxs, Mins;
    deque<ll> qMax, qMin; // 存下标

    for (ll i = 1; i <= n; i++)
    {

        while (!qMax.empty() && num[qMax.back()] <= num[i])
        {
            qMax.pop_back();
        }
        qMax.push_back(i);
        while (!qMin.empty() && num[qMin.back()] >= num[i])
        {
            qMin.pop_back();
        }
        qMin.push_back(i);

        while (!qMax.empty() && qMax.front() <= i - k)
        {
            qMax.pop_front();
        }
        while (!qMin.empty() && qMin.front() <= i - k)
        {
            qMin.pop_front();
        }

        if (i >= k)
        {
            Maxs.push_back(num[qMax.front()]);
            Mins.push_back(num[qMin.front()]);
        }
    }

    for (ll a : Mins)
    {
        cout << a << ' ';
    }
    cout << endl;

    for (ll a : Maxs)
    {
        cout << a << ' ';
    }
    cout << endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.