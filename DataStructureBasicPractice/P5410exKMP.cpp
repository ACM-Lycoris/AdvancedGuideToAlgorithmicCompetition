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

    string a, b;
    cin >> a >> b;

    auto makeZ = [&](const string &s) -> vector<ll>
    {
        ll n = s.size();
        vector<ll> z(n);
        // 这里已经是1--n+1的1-based
        n--;
        z[1] = n;
        for (ll i = 2, L = 1, R = 1; i <= n; i++)
        {
            if (i <= R)
            {
                z[i] = min(R - i + 1, z[i - L + 1]);
            }
            while (i + z[i] <= n && s[i + z[i]] == s[1 + z[i]])
            {
                z[i]++;
            }
            if (i + z[i] - 1 > R)
            {
                R = i + z[i] - 1;
                L = i;
            }
        }
        return z;
    };

    ll Valz = 0;
    ll lenB = b.length();
    b = ' ' + b;
    vector<ll> zb = makeZ(b);

    for (ll i = 1; i <= lenB; i++)
    {
        Valz ^= (i * (zb[i] + 1));
    }

    cout << Valz << endl;
    ll lenA = a.length();
    a = ' ' + a;
    vector<ll> zp(lenA + 1);

    for (ll i = 1, L = 1, R = 0; i <= lenA; i++)
    { // L,R都是对于a的
        if (i <= R)
        {
            zp[i] = min(R - i + 1, zb[i - L + 1]);
        }

        while (i + zp[i] <= lenA                  // A不越界
               && 1 + zp[i] <= lenB               // B不越界
               && (a[i + zp[i]] == b[1 + zp[i]])) // 相等
        {
            zp[i]++;
        }

        if (i + zp[i] - 1 > R)
        {
            R = i + zp[i] - 1;
            L = i;
        }
    }

    ll valP = 0;
    for (ll i = 1; i <= lenA; i++)
    {
        valP ^= (i * (zp[i] + 1));
    }
    cout << valP << endl;
    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.