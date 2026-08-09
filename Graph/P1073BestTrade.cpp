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

// 用三层分层图+双端SPFA实现
const ll N = 100010;
const ll MAXN = 300010, MAXM = 3250010;
// 一层一百万条边，再加2e5条跨层边

ll Head[MAXN];
ll To[MAXM], Next[MAXM], W[MAXM];
ll tot;

ll a[N]; // 点权

inline void add(ll a, ll b, ll w)
{
    tot++;
    To[tot] = b;
    W[tot] = w;
    Next[tot] = Head[a];
    Head[a] = tot;
}

inline ll id(ll layer, ll i)
{
    return layer * n + i;
}

const ll NEG = -0x3f3f3f3f3f3f3f3fLL;
ll dist[MAXN];
bool inq[MAXN];

int main()
{
    optimize();

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    while (m--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        // 三层图里面路要同步
        // 先建立层内边
        for (int layer = 0; layer < 3; layer++)
        {
            add(id(layer, x), id(layer, y), 0);
            if (z == 2)
            {
                add(id(layer, y), id(layer, x), 0);
            }
        }
    }

    // 再建立跨层边
    for (int i = 1; i <= n; i++)
    {
        add(id(0, i), id(1, i), -a[i]); // 买入定负权
        add(id(1, i), id(2, i), a[i]);  // 卖出定正权
    }

    ll V = 3 * n;
    for (int i = 1; i <= V; i++)
    {
        dist[i] = NEG;
        inq[i] = false;
    }

    queue<ll> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        inq[u] = false;

        for (int i = Head[u]; i; i = Next[i])
        {
            int v = To[i];
            int w = W[i];
            if (dist[u] + w > dist[v])
            {
                // 注意这里的大于号，要找赚钱最多的最长路
                dist[v] = dist[u] + w;
                if (!inq[v])
                {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }

    ll ans = (dist[3 * n] == NEG ? 0 : max(0LL, dist[3 * n]));
    cout << ans << endl;

    return 0;
}