// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

const int N = 1e5 + 10;

int son[N * 32][2];
vector<vector<pair<int, int>>> graph;
int dist[N];
int idx;

void Insert(const int &a)
{
    int u = 0;
    for (int i = 30; i >= 0; i--)
    {
        int bit = (a >> i) & 1;
        if (son[u][bit] == 0)
        {
            son[u][bit] = ++idx;
        }
        u = son[u][bit];
    }
}

void DFS(int u, int father)
{

    for (auto [v, w] : graph[u])
    {
        if (v == father)
        {
            continue;
        }
        dist[v] = dist[u] ^ w;
        DFS(v, u);
    }
}

int Query(const int &x)
{
    int u = 0;
    int ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        int bit = (x >> i) & 1;
        int want = bit ^ 1;
        if (son[u][want] != 0)
        {
            ans |= (1 << i);
            u = son[u][want];
        }
        else
        {
            u = son[u][bit];
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    graph.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    dist[0] = 0;
    dist[1] = 0;
    DFS(1, 0);

    for (int i = 1; i <= n; i++)
    {
        Insert(dist[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, Query(dist[i]));
    }

    cout << ans << endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.