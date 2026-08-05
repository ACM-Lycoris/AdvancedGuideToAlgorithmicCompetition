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
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<ll> Tree(4 * n + 5);
    vector<ll> lazy(4 * n + 5,0);
    auto build = [&](auto &&self, ll p, ll l, ll r) -> void
    {
        if (l == r)
        {
            Tree[p] = a[l];
            return;
        }

        ll mid = l + (r - l) / 2;
        self(self, p * 2, l, mid);
        self(self, p * 2 + 1, mid + 1, r);

        Tree[p] = Tree[p * 2] + Tree[p * 2 + 1];
    };

    auto apply = [&](ll p, ll l, ll r, ll k) -> void // 区间修改前置申请函数
    {
        Tree[p] += (r - l + 1) * k;
        lazy[p] += k;
    };

    auto pushDown = [&](ll p, ll l, ll r) -> void // 前置下放懒标记函数
    {
        if (lazy[p] == 0 || l == r)
        {
            return; // 遇到这里就返回滚木
        }

        ll mid = l + (r - l) / 2;
        apply(p * 2, l, mid, lazy[p]);
        apply(p * 2 + 1, mid + 1, r, lazy[p]);
        lazy[p] = 0; // 结束
    };

    auto update = [&](auto &&self, ll p, ll l, ll r, ll k, ll ql, ll qr) -> void
    {
        if (ql <= l && r <= qr)
        {
            apply(p, l, r, k);
            return;
        }

        pushDown(p, l, r);
        ll mid = l + (r - l) / 2;
        if (ql <= mid)
        {
            self(self, p * 2, l, mid, k, ql, qr);
        }
        if (qr > mid)
        {
            self(self, p * 2 + 1, mid + 1, r, k, ql, qr);
        }

        Tree[p] = Tree[p * 2] + Tree[p * 2 + 1];
    };

    auto query = [&](auto &&self, int p, int l, int r,int ql, int qr) -> ll
    {
        if (ql <= l && r <= qr)
        {
            return Tree[p];
        }

        pushDown(p, l, r);

        int mid = l + (r - l) / 2;
        ll ans = 0;

        if (ql <= mid)
        {
            ans += self(self, p * 2, l, mid, ql, qr);
        }

        if (qr > mid)
        {
            ans += self(self, p * 2 + 1, mid + 1, r, ql, qr);
        }

        return ans;
    };

    build(build,1,1,n);

    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll x, y, k;
            cin >> x >> y >> k;
            update(update,1,1,n,k,x,y);
        }
        else
        {
            ll x, y;
            cin >> x >> y;
            ll ans=query(query,1,1,n,x,y);
            cout<<ans<<'\n';
        }
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.