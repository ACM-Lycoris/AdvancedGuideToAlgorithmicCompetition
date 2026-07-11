  // The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

inline void optimizeIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    optimizeIO();

    ll n;
    cin >> n;
      // vector<ll> A(n);
      // for(int i=0;i<n;i++){
      //   cin>>A[i];
      //}

    vector<pair<ll, ll>> Val(n + 2);
    vector<ll> L(n + 2, 0), R(n + 2, 0);
    Val[n + 1].first = INT_MAX;
    Val[0].first     = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        cin >> Val[i].first;
        Val[i].second = i;
        L  [i]        = i - 1;
        R  [i]        = i + 1;
    }

    sort(Val.begin(), Val.end());

    vector<ll> pos(n + 2);
    for (int i = 1; i <= n; i++)
    {
        pos[Val[i].second] = i;  // 原来索引与现在索引对应的关系
    }

    vector<pair<ll, ll>> res(n);  // minDiff & Pi(j)

    for (int i = n; i >= 2; i--)
    {
        ll k     = pos[i];
        ll cur   = Val[k].first;
        ll Left  = Val[L[k]].first;
        ll Right = Val[R[k]].first;

        ll Diff1 = abs(cur - Left);
        ll Diff2 = abs(cur - Right);

        if (Diff1 <= Diff2)
        {
            res[i - 1].first  = Diff1;
            res[i - 1].second = Val[L[k]].second;
        }
        else
        {
            res[i - 1].first  = Diff2;
            res[i - 1].second = Val[R[k]].second;
        }

        R[L[k]] = R[k];
        L[R[k]] = L[k];
    }

    for (int i = 1; i < n; i++)
    {
        cout << res[i].first << ' ' << res[i].second << '\n';
    }

    return 0;
}
  // The answer is in the depth of five fathoms. And has always been her.