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

const int N = 25010;
const int M = 200005;
const int INF = 0x3f3f3f3f;

int Head[N], Next[M], To[M], W[M];
int tot;

inline void add(int a, int b, int w)
{
    tot++;
    To[tot] = b;
    W[tot] = w;
    Next[tot] = Head[a];
    Head[a] = tot;
}

int fa[N];

int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

int T, R, P, S;
int bc;               // blockCnt
int id[N];            // 初始化点->块
int blk[N];           // 点u属于哪个块
vector<int> nodes[N]; // 每个块下面的所有点

int deg[N]; // 入度
int dis[N]; // Dij用数组
bool vis[N];

int main()
{
    optimize();

    cin >> T >> R >> P >> S;

    for (int i = 0; i <= T; i++)
    {
        fa[i] = i;//初始化fa数组
    }

    for (int i = 1; i <= R; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
        int ra = find(a), rb = find(b);
        fa[ra] = rb;//写回fa数组
    }

    for (int u = 1; u <= T; u++)
    {
        int r = find(u); // 找到祖先点
        if (!id[r])
        {
            id[r] = ++bc;
        }
        blk[u] = id[r];
        nodes[blk[u]].emplace_back(u);
    }

    for (int i = R + 2; i <= R + P + 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        add(a, b, c);
        deg[blk[b]]++;
    }

    priority_queue<int, vector<int>, greater<int>> tq; // 拓扑排序用
    for (int i = 1; i <= bc; i++)
    {
        if (deg[i] == 0)
        {
            tq.push(i);
        }
    }

    memset(dis, 0x3f, sizeof(dis));
    dis[S] = 0;
    memset(vis, 0, sizeof(vis));

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Dij

    while (!tq.empty())
    {
        int cur = tq.top();
        tq.pop();

        // 一个块内部先dij

        for (int v : nodes[cur])
        {
            pq.push({dis[v], v});
        }

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if (vis[u])
            {
                continue;
            }
            vis[u] = true;

            bool same = true;

            for (int i = Head[u]; i; i = Next[i])
            {
                int v = To[i];
                int w = W[i];

                if (blk[u] == blk[v])
                {
                    same = true;
                }
                else
                {
                    same = false;
                }

                if (dis[u] != INF && dis[u] + w < dis[v])
                {
                    dis[v] = dis[u] + w;
                    if (same)
                    {
                        pq.push({dis[v], v});
                    }
                }
                if (!same)
                {
                    deg[blk[v]]--;
                    if (deg[blk[v]] == 0)
                    {
                        tq.push(blk[v]); // 这里应该放入块号
                    }
                }
            }
        }
    }

    for (int i = 1; i <= T; i++)
    {
        if (dis[i] > INF / 2)
        {
            cout << "NO PATH\n";
        }
        else
        {
            cout << dis[i] << '\n';
        }
    }

    return 0;
}