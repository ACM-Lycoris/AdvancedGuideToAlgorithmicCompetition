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

#define ls p << 1
#define rs p << 1 | 1
#define mid ((l + r) >> 1)

ll n, m;
const ll N = 100005;
ll Tree[N << 2];
ll a[N];
void build(ll p, ll l, ll r)
{

    if (l == r)
    {
        Tree[p] = a[l];
        return;
    }

    build(ls, l, mid);
    build(rs, mid + 1, r);

    Tree[p] = Tree[ls] + Tree[rs];
}

void upd(ll p, ll l, ll r, ll ql, ll qr)
{

    if (r < ql || qr < l)
    {
        return;
    }
    if (Tree[p] == r - l + 1)
    {
        return;
    }

    if (l == r)
    {
        Tree[p] = (ll)(sqrtl((long double)(Tree[p])));
        return;
    }
    upd(ls, l, mid, ql, qr);
    upd(rs, mid + 1, r, ql, qr);
    Tree[p] = Tree[ls] + Tree[rs];
}

ll q(ll p, ll l, ll r, ll ql, ll qr)
{

    if (r < ql || qr < l)
    {
        return 0;
    }
    if (ql <= l && r <= qr)
    {
        return Tree[p];
    }

    if (qr<=mid)
    {
        return q(ls, l, mid, ql, qr);
    }
    if (mid<ql)
    {
        return q(rs, mid + 1, r, ql, qr);
    }

    return q(ls, l, mid, ql, qr) + q(rs, mid + 1, r, ql, qr);
}

int main()
{
    optimize();

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    build(1, 1, n);

    cin >> m;

    while (m--)
    {
        ll k, l, r;
        cin >> k >> l >> r;
        if (l > r)
        {
            swap(l, r);
        }
        if (k == 0)
        {
            upd(1, 1, n, l, r);
        }
        else
        {
            //   cerr<<q(1,1,n,l,r)<<endl;
            cout << q(1, 1, n, l, r) << '\n';
        }
    }

    return 0;
}