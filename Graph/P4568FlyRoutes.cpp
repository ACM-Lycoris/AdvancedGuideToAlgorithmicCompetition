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

int n, m, k;
const int N = 10005;
const int MAXN = 230005, MAXM = 50000 * 42 + 10;

int Head[MAXN];
int To[MAXM], Next[MAXM], W[MAXM];
int tot;

const int INF = 0x3f3f3f3f;

inline int id(int k, int i)
{
    return k * n + i;
}

inline void add(int a, int b, int w)
{
    tot++;
    To[tot] = b;
    W[tot] = w;
    Next[tot] = Head[a];
    Head[a] = tot;
}

int dist[MAXN];
bool vis[MAXN]; // 可以用Dijkstra解决

int main()
{
    optimize();

    cin >> n >> m >> k;

    int s, t;
    cin >> s >> t;
    s++, t++;

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a++, b++; // 转换1-based

        for (int j = 0; j <= k; j++)
        {
            add(id(j, a), id(j, b), c);
            add(id(j, b), id(j, a), c);
            if (j < k)
            {
                add(id(j, a), id(j + 1, b), 0);//这里是a到b的跨层边而不是原地跨层
                add(id(j, b), id(j + 1, a), 0);
            }
        }
    }

    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (vis[u])
        {
            continue;
        }
        vis[u] = true;

        for (int i = Head[u]; i; i = Next[i])
        {
            int v = To[i];
            int w = W[i];

            if (d + w < dist[v])
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = INF;

    for (int j = 0; j <= k; j++)
    {
        ans = min(ans, dist[id(j, t)]);
    }

    cout << ans << endl;

    return 0;
}