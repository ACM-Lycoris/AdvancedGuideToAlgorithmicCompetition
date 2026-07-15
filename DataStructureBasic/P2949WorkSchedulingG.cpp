// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<pair<ll, ll>> Task(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> Task[i].first >> Task[i].second;
    }

    if (n == 1)
    {
        cout << Task[0].second << endl;
        return 0;
    }

    priority_queue<ll, vector<ll>, greater<ll>> pq; // 大根堆

    sort(Task.begin(), Task.end());

    ll curTime = 1;
    ll BestMoney = 0;

    for (ll i = 0; i < n; i++)
    {
        ll curDDL = Task[i].first;
        ll curP = Task[i].second;

        if (curTime <= curDDL)
        {
            pq.push(curP);
        }

        while (pq.size() > curDDL)
        {
            pq.pop();
        }
    }

    while (!pq.empty())
    {
        ll curP = pq.top();
        pq.pop();
        // curTime++;
        BestMoney += curP;
    }

    cout << BestMoney << '\n';

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.