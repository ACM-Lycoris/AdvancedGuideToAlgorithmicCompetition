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

ll n, m;
const ll N = 5e5 + 10;

struct Node
{
    ll Sum;
    ll lMax;
    ll rMax;
    ll Max;
};

ll a[N];
Node Tree[N << 2];

Node Merge(const Node &A, const Node &B)
{
    Node node;
    node.Sum = A.Sum + B.Sum;
    node.lMax = max(A.lMax, (A.Sum + B.lMax));
    node.rMax = max(B.rMax, (B.Sum + A.rMax));
    node.Max = max(max(A.Max, B.Max), A.rMax + B.lMax);
    return node;
}

#define ls (p << 1)
#define rs (p << 1 | 1)

void build(int p, int l, int r)
{
    if (l == r)
    {
        Tree[p] = {a[l], a[l], a[l], a[l]};
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    Tree[p] = Merge(Tree[ls], Tree[rs]);
}

void Modify(int p, int l, int r, int pos, int v)
{
    if (l == r)
    {
        Tree[p] = {v, v, v, v};
        return;
    }
    int mid = (l + r) >> 1;

    if (pos <= mid)
    {
        Modify(ls, l, mid, pos, v);
    }
    else
    {
        Modify(rs, mid + 1, r, pos, v);
    }
    Tree[p] = Merge(Tree[ls], Tree[rs]);
}

Node Query(int p, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return Tree[p];
    }
    int mid = (l + r) >> 1;
    if (qr <= mid)
    {
        return Query(ls, l, mid, ql, qr);
    }
    else if (ql > mid)
    {
        return Query(rs, mid + 1, r, ql, qr);
    }
    return Merge(Query(ls, l, mid, ql, qr), Query(rs, mid + 1, r, ql, qr));
}

int main()
{
    optimize();

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    build(1,1,n);

    while (m--)
    {
        int k;
        cin >> k;
        if (k == 1)
        {
            int x, y;
            cin >> x >> y;
            if (x > y)
            {
                swap(x, y);
            }
            cout << Query(1, 1, n, x, y).Max << endl;
        }
        else
        {
            int p, s;
            cin >> p >> s;
            Modify(1, 1, n, p, s);
        }
    }

    return 0;
}