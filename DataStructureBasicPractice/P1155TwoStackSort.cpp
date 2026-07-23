// The answer is in the depth of five fathoms. Waiting to be retrieved.
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

int main()
{
    optimize();

    int n;
    cin >> n;
    vector<int> a(n + 1); // 原始数组
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> graph(n + 1);   // 二分图
    vector<int> sufMin(n + 1, INT_MAX); // 后缀最小值

    for (int i = n; i >= 1; i--)
    {
        if (i == n)
        {
            sufMin[i] = a[i];
        }
        else
        {
            sufMin[i] = min(a[i], sufMin[i + 1]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j] && sufMin[j + 1] < a[i])
            {
                // 意味着存在这样一个冲突
                graph[i].emplace_back(j);
                graph[j].emplace_back(i);
            }
        }
    }

    // 染色
    vector<int> color(n + 1, 0); // 每一个节点，0表示未染色，1表示进入S1,2表示进入S2
    bool could = true;           // 是否可行

    for (int i = 1; i <= n; i++)
    { // 尝试对所有连通块广搜一次
        if (color[i] != 0)
        {
            continue;
        }

        queue<int> q; // 广搜染色用队列
        q.push(i);
        color[i] = 1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : graph[u])
            {
                if (color[v] == 0)
                {
                    color[v] = 3 - color[u];
                }
                else
                {
                    if (color[v] == 3 - color[u])
                    {
                        continue;
                    }
                    else
                    {
                        // 出现奇环冲突
                        // 直接确认不行
                        could = false;
                        goto end_loop;
                    }
                }
                q.push(v);
            }
        }
    }

end_loop:
{

    if (!could)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        // output

        int need = 1, pos = 1;
        // 入栈时控制pos,压入a[pos]
        // 出栈时控制need++;
        stack<int> st1, st2;

        vector<char> result; // 结果

        while (need <= n)
        {

            // a:push in S1
            if (pos <= n && color[pos] == 1 && (st1.empty() || (!st1.empty() && a[pos] <= st1.top())))
            {
                st1.push(a[pos]);
                pos++;
                result.push_back('a');
                continue;
            }

            // b: s1 pop
            if (!st1.empty() && st1.top() == need)
            {
                need++;
                st1.pop();
                result.push_back('b');
                continue;
            }

            // c:push in S2
            if (pos <= n && color[pos] == 2 && (st2.empty() || (!st2.empty() && a[pos] <= st2.top())))
            {
                st2.push(a[pos]);
                pos++;
                result.push_back('c');
                continue;
            }

            // d: s2 pop
            if (!st2.empty() && st2.top() == need)
            {
                need++;
                st2.pop();
                result.push_back('d');
                continue;
            }
        }

        for (const char &c : result)
        {
            cout << c << ' ';
        }
        cout << endl;
    }
};

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.