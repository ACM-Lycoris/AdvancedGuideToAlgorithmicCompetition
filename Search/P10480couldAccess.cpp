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
const int N = 3e4 + 10;

int Head[N];
int To[N], Next[N]; // 不需要边权数组
int tot;

void add(int a, int b)
{
    tot++;
    To[tot] = b;
    Next[tot] = Head[a];
    Head[a] = tot;
}

int inQ[N];

int main()
{
    optimize();

    tot = 0;
    cin >> n >> m;

    queue<int> topoQ;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        inQ[b]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (inQ[i] == 0)
        {
            topoQ.push(i); // 入度为0先入队
        }
    }

    vector<int> topo;

    while (!topoQ.empty())
    {
        int u = topoQ.front();
        topoQ.pop();

        for (int i = Head[u]; i; i = Next[i])
        {
            int v = To[i];
            inQ[v]--;
            if (inQ[v] == 0)
            {
                topoQ.push(v);
            }
        }

        topo.emplace_back(u);
    }

    static bitset<N> reach[N];

    for (int i = n - 1; i >= 0; i--)
    {
        // 逆序拓扑dp

        int u = topo[i];

        reach[u][u] = 1;

        for (int j = Head[u]; j; j = Next[j])
        {
            int v = To[j];
            reach[u] |= reach[v];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << reach[i].count() << '\n';
    }

    return 0;
}