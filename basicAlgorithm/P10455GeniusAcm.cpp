// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

inline void optimizeIO()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool check(const vector<ll> &a, ll m, ll k)
{
    ll sum = 0;
    ll len = a.size();
    for (ll i = 0; i < min((len / 2), m); i++)
    {
        sum += (a[len - 1 - i] - a[i]) * (a[len - 1 - i] - a[i]);
        if (sum > k)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    optimizeIO();

    ll T;
    cin >> T;

    while (T--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> nums(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        ll res = 0;
        ll l = 0;

        while (l < n)
        {
            ll r = l - 1; // 先开一个虚空右边界
            ll step = 1;
            vector<ll> curSorted; // 虚空数组，从当前左边界到当前右边界的

            while (step)
            {

                ll nextR = r + step;
                if (nextR < n)
                {
                    
                    vector<ll> nextPart(nums.begin() + r + 1, nums.begin() + nextR + 1);
                    sort(nextPart.begin(),nextPart.end());
                    
                    vector<ll> Merge;
                    Merge.reserve(curSorted.size() + nextPart.size());
                    merge(curSorted.begin(), curSorted.end(),
                          nextPart.begin(), nextPart.end(),
                          back_inserter(Merge));

                    if (check(Merge, m, k))
                    {
                        // 合法
                        step = min(step * 2, n - 1 - r);
                        r = nextR;
                        curSorted = move(Merge);
                        continue;
                    }else{
                        step>>=1;
                    }
                }else{
                    step>>=1;
                }
            }
            // 直到step=0.
            res++;
            l = r + 1;

        }

        cout << res << endl;
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.