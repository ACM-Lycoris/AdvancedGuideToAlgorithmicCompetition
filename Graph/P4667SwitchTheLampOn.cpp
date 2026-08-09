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

int n, m;
const int N = 505, M = 505;
const int MAXN = 251005;  // 点的数量
const int MAXM = 1000005; // 边的数量
const int INF = 0x3f3f3f3f;

int Head[MAXN];
int To[MAXM], Next[MAXM], W[MAXM];
int tot;

int dist[MAXN], vis[MAXN];

int id(int x, int y)
{
    return (x - 1) * (m + 1) + y;
}

void add(int i, int j, int w)
{
    tot++;
    To[tot] = j;
    W[tot] = w;
    Next[tot] = Head[i];
    Head[i] = tot;
}

void Add(int x, int y, char op)
{
    int p1, p2, p3, p4;
    // p1p2之间建两条边,p3p4间建两条边
    if (op == '/')
    {
        p1 = id(x + 1, y), p2 = id(x, y + 1), p3 = id(x, y), p4 = id(x + 1, y + 1);
    }
    else
    {
        p1 = id(x, y), p2 = id(x + 1, y + 1), p3 = id(x + 1, y), p4 = id(x, y + 1);
    }
    add(p1, p2, 0);
    add(p2, p1, 0);
    add(p3, p4, 1);
    add(p4, p3, 1);
}

int main()
{
    optimize();

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string ops;
        cin >> ops;
        for (int j = 1; j <= m; j++)
        {
            Add(i, j, ops[j - 1]);
        }
    }

    deque<int> dq;
    dq.push_front(1);
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[1] = 0;

    while (!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();
        if (vis[u])
        {
            continue;
        }
        vis[u] = 1;

        for (int i = Head[u]; i; i = Next[i])
        {
            int v = To[i];
            int c = W[i];
            if (dist[u] + c < dist[v])
            {
                dist[v] = dist[u] + c;
                if (c == 0)
                {
                    dq.push_front(v);
                }
                else
                {
                    dq.push_back(v);
                }
            }
        }
    }

    int End = id(n + 1, m + 1);

    if (dist[End] >= INF)
    {
        cout << "NO SOLUTION\n";
    }
    else
    {
        cout << dist[End] << "\n";
    }

    return 0;
}