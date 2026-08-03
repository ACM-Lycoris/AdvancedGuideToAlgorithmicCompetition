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
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<ll> Tree(4 * n + 5, 0);
    auto build = [&](auto &&self, int p, int l, int r) -> void
    {
        if (l == r)
        {
            Tree[p] = a[l];
            return;
        }

        int mid = l + (r - l) / 2;

        self(self, p * 2, l, mid);
        self(self, p * 2 + 1, mid + 1, r);

        Tree[p] = max(Tree[p * 2], Tree[p * 2 + 1]);
    };

    auto update = [&](auto &&self, int p, int pos, int val, int l, int r) -> void
    {
        if (l == r)
        {
            Tree[p] = max((ll)val, Tree[p]);
            return;
        }

        int mid = l + (r - l) / 2;
        if (pos <= mid)
        {
            self(self, p * 2, pos, val, l, mid);
        }
        else
        {
            self(self, p * 2 + 1, pos, val, mid + 1, r);
        }

        Tree[p] = max(Tree[p * 2], Tree[p * 2 + 1]);
    };

    auto query = [&](auto &&self, int p, int l, int r, int ql, int qr) -> ll
    {
        if (ql <= l && r <= qr)
        {
            return Tree[p];
        }
        if (l>qr || r < ql)
        {
            return 0;
        }
        int mid = l + (r - l) / 2;

        ll leftMax = self(self, p * 2, l, mid, ql, qr);
        ll rightMax = self(self, p * 2 + 1, mid + 1, r, ql, qr);

        return max(leftMax, rightMax);
    };

    build(build, 1, 1, n);

    while (m--)
    {

        char c;
        cin >> c;
        if (c == 'Q')
        {
            int ql, qr;
            cin >> ql >> qr;
            ll ans = query(query, 1, 1, n, ql, qr);
            cout << ans << '\n';
        }
        else
        {
            int a, b;
            cin >> a >> b;
            update(update, 1, a, b, 1, n);
        }
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.