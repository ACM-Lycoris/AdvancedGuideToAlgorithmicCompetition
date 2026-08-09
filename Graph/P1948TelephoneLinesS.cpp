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

int n, p, k;
const int N = 1005;         // node
const int M = 20005;        // edges
const int INF = 0x3f3f3f3f; //

int tot;                    // 边id
int To[M], Next[M], Wei[M]; // 边池
int Head[N];                // 点的头

int dis[N], vis[N];

inline void add(int u, int v, int w)
{
    tot++;
    To[tot] = v;
    Wei[tot] = w;
    Next[tot] = Head[u]; // 接边
    Head[u] = tot;       // 换头
}

bool check(int x)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));

    deque<int> dq;
    dq.push_front(1);
    dis[1] = 0;

    while (!dq.empty())
    {

        int u = dq.front();
        dq.pop_front();

        if (vis[u])
        {
            continue; // 判重
        }
        vis[u] = 1;

        for (int i = Head[u]; i; i = Next[i])
        {
            // 对这一条边
            int v = To[i];
            int c = (Wei[i] > x) ? 1 : 0;
            if (dis[u] + c < dis[v])
            {
                dis[v]=dis[u]+c;
                if (c == 1)
                {
                    dq.push_back(v);
                }
                else
                {
                    dq.push_front(v);
                }
            }
        }
    }
    if (dis[n] > k)
    { // 免费需求过高，或者直接不可达(>k已包含INF)
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    optimize();

    cin >> n >> p >> k;

    while (p--)
    {
        int a, b, l;
        cin >> a >> b >> l;
        add(a, b, l);
        add(b, a, l);
    }

    int l = 0, r = 1e6 + 3;
    bool found = false;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
        {
            found = true; // 可行标记
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << (found ? r : -1) << endl;

    return 0;
}