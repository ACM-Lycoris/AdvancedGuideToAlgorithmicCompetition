#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

inline void optimize()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

#define ls (p << 1)
#define rs (p << 1 | 1)

ll n, q, m;
const ll N = 1e5 + 10, MOD = 571373;

ll Tree[N << 2], LazyPlus[N << 2], LazyMul[N << 2];
ll a[N];

void build(ll p, ll l, ll r)
{
    LazyMul[p]  = 1;  // 初始化乘法懒标记为1
    LazyPlus[p] = 0;  // 初始化加法懒标记为0
    if (l == r)
    {
        Tree[p] = a[l] % MOD;
        return;
    }
    ll mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    Tree[p] = (Tree[ls] + Tree[rs]) % MOD;
}

void applyPlus(ll p, ll l, ll r, ll v);
void applyMul(ll p, ll l, ll r, ll v);

void applyPlus(ll p, ll l, ll r, ll v)
{
    Tree[p]     = (Tree[p] + (r - l + 1) * v) % MOD;
    LazyPlus[p] = (LazyPlus[p] + v) % MOD;
}

void applyMul(ll p, ll l, ll r, ll v)
{
    Tree[p]     = Tree[p] * v % MOD;
    LazyMul[p]  = LazyMul[p] * v % MOD;
    LazyPlus[p] = LazyPlus[p] * v % MOD;
}

void Push(ll p, ll l, ll r)
{
    if (l == r || (LazyMul[p] == 1 && LazyPlus[p] == 0))
    {
        return;
    }

    if (LazyMul[p] != 1)
    {
        ll mid = (l + r) >> 1;
        applyMul(ls, l, mid, LazyMul[p]);
        applyMul(rs, mid + 1, r, LazyMul[p]);
        LazyMul[p] = 1;  // 重置乘法懒标记为1
    }
    if (LazyPlus[p] != 0)
    {
        ll mid = (l + r) >> 1;
        applyPlus(ls, l, mid, LazyPlus[p]);
        applyPlus(rs, mid + 1, r, LazyPlus[p]);
        LazyPlus[p] = 0;
    }
}

void updPlus(ll p, ll l, ll r, ll ql, ll qr, ll x)
{
      // 区间加
    if (ql <= l && r <= qr)
    {
        applyPlus(p, l, r, x);
        return;
    }
    Push(p, l, r);
    ll mid = (l + r) >> 1;
    if (ql <= mid)
    {
        updPlus(ls, l, mid, ql, qr, x);
    }
    if (qr > mid)
    {
        updPlus(rs, mid + 1, r, ql, qr, x);
    }
    Tree[p] = (Tree[ls] + Tree[rs]) % MOD;
}

void updMul(ll p, ll l, ll r, ll ql, ll qr, ll x)
{
      // 区间乘
    if (ql <= l && r <= qr)
    {
        applyMul(p, l, r, x);
        return;
    }
    Push(p, l, r);
    ll mid = (l + r) >> 1;
    if (ql <= mid)
    {
        updMul(ls, l, mid, ql, qr, x);
    }
    if (qr > mid)
    {
        updMul(rs, mid + 1, r, ql, qr, x);
    }
    Tree[p] = (Tree[ls] + Tree[rs]) % MOD;
}

ll Query(ll p, ll l, ll r, ll ql, ll qr)
{
      // 区间查询
    if (ql <= l && r <= qr)
    {
        return Tree[p] % MOD;
    }
    Push(p, l, r);
    ll mid = (l + r) >> 1;
    ll ans = 0;
    if (ql <= mid)
        ans = (Query(ls, l, mid, ql, qr) + ans) % MOD;
    if (qr > mid)
        ans = (Query(rs, mid + 1, r, ql, qr) + ans) % MOD;
    return ans % MOD;
}

int main()
{
    optimize();

    cin >> n >> q >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);

    while (q--)
    {
        ll op;
        cin >> op;
        if (op == 1)
        {
              // 区间乘
            ll x, y, k;
            cin >> x >> y >> k;
            updMul(1, 1, n, x, y, k);
        }
        else if (op == 2)
        {
            ll x, y, k;
            cin >> x >> y >> k;
            updPlus(1, 1, n, x, y, k);
        }
        else
        {
            ll x, y;
            cin >> x >> y;
            cout << Query(1, 1, n, x, y) << '\n';
        }
    }

    return 0;
}
