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

int n, m;
const int N = 100005;

struct Node
{
    int len;
    int sum; // 区间内1的个数
    int lmax[2];
    int rmax[2];
    int max[2]; // max[v]最长连续v的长度
};

int a[N];
Node Tree[N << 2];
int LazySet[N << 2]; // 赋值懒标记
int LazyRev[N << 2]; // 取反懒标记

void putSet(int p, int v)
{
    int Len = Tree[p].len;
    Tree[p].sum = v * Len;
    Tree[p].lmax[v] = Tree[p].rmax[v] = Tree[p].max[v] = Len;
    Tree[p].lmax[v ^ 1] = Tree[p].rmax[v ^ 1] = Tree[p].max[v ^ 1] = 0;
    LazyRev[p] = 0; // 直接覆盖
    LazySet[p] = v;
}

void putRev(int p)
{
    int Len = Tree[p].len;
    Tree[p].sum = Len - Tree[p].sum;
    swap(Tree[p].lmax[0], Tree[p].lmax[1]);
    swap(Tree[p].rmax[0], Tree[p].rmax[1]);
    swap(Tree[p].max[0], Tree[p].max[1]);

    if (LazySet[p] != -1)
    {
        // 直接打在赋值懒标记上
        LazySet[p] ^= 1;
    }
    else
    {
        LazyRev[p] ^= 1;
    }
}

void Push(int p)
{
    if (LazySet[p] != -1)
    {
        putSet(ls, LazySet[p]);
        putSet(rs, LazySet[p]);
        LazySet[p] = -1;
    }
    if (LazyRev[p])
    {
        putRev(ls);
        putRev(rs);
        LazyRev[p] = 0;
    }
}

Node Merge(const Node &A, const Node &B)
{
    Node C;
    C.sum = A.sum + B.sum;
    C.len = A.len + B.len;
    for (int v = 0; v <= 1; v++)
    {
        C.lmax[v] = A.lmax[v] + (A.lmax[v] == A.len ? B.lmax[v] : 0);
        C.rmax[v] = B.rmax[v] + (B.rmax[v] == B.len ? A.rmax[v] : 0);
        C.max[v] = max(max(A.max[v], B.max[v]), A.rmax[v] + B.lmax[v]);
    }
    return C;
}

void build(int p, int l, int r)
{
    LazySet[p] = -1;
    LazyRev[p] = 0;
    if (l == r)
    {
        Tree[p].len = 1;
        Tree[p].sum = a[l];
        for (int i = 0; i <= 1; i++)
        {
            Tree[p].lmax[i] = (a[l] == i);
            Tree[p].rmax[i] = (a[r] == i);
            Tree[p].max[i] = (a[l] == i);
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);

    Tree[p] = Merge(Tree[ls], Tree[rs]);
}

void upd(int p, int l, int r, int ql, int qr, int op)
{
    if (ql <= l && r <= qr)
    {

        if (op == 0)
        {
            putSet(p, 0);
        }
        if (op == 1)
        {
            putSet(p, 1);
        }
        if (op == 2)
        {
            putRev(p);
        }

        return;
    }
    Push(p);
    int mid = (l + r) >> 1;
    if (ql <= mid)
    { // 修改函数应该是哪边有交集就递归哪边
        upd(ls, l, mid, ql, qr, op);
    }
    if (qr > mid)
    {
        upd(rs, mid + 1, r, ql, qr, op);
    }
    Tree[p] = Merge(Tree[ls], Tree[rs]);
}

Node q(int p, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return Tree[p];
    }
    Push(p);
    int mid = (l + r) >> 1;
    if (qr <= mid)
    {
        return q(ls, l, mid, ql, qr);
    }
    if (ql > mid)
    {
        return q(rs, mid + 1, r, ql, qr);
    }
    Node A = q(ls, l, mid, ql, qr), B = q(rs, mid + 1, r, ql, qr);
    return Merge(A, B);
}

int main()
{
    optimize();

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    build(1, 1, n);

    while (m--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        l++;
        r++;
        if (op == 0 || op == 1 || op == 2)
        {
            upd(1, 1, n, l, r, op);
        }
        if (op == 3)
        {
            cout << (q(1, 1, n, l, r).sum) << '\n';
        }
        if (op == 4)
        {
            cout << (q(1, 1, n, l, r).max[1]) << '\n';
        }
    }

    return 0;
}