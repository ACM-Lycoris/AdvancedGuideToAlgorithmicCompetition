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

const ull p = 131;

int main()
{
    optimize();

    ull m, n, a, b;
    cin >> m >> n >> a >> b;

    vector<ull> power(a * b + 10);
    power[0] = 1;
    for (ull i = 1; i <= a * b + 5; i++)
    {
        power[i] = power[i - 1] * p;
    }

    vector<vector<ull>> h(m + 1, vector<ull>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        string line;
        cin >> line;
        line = ' ' + line;
        for (int j = 1; j <= n; j++)
        {
            h[i][j] = h[i][j - 1] * p + int(line[j] - '0');
        }
    }

    vector<ull> allHash;

    for (int right = b; right <= n; right++)
    {

        int left = right - b + 1;

        ull curHash=0; // 当前的区域字符串哈希
        // 这里的字符串定义为A*B块的压缩字符串

        for (int row = 1; row <= m; row++)
        {

            ull curRowHash = h[row][right] - h[row][left - 1] * power[b];

            curHash = curRowHash + curHash * power[b];

            if (row > a)
            {
                int oldRow = row - a;
                ull oldRowHash = h[oldRow][right] - h[oldRow][left - 1] * power[b];
                curHash -= oldRowHash * power[a * b];
            }
            if (row >= a)
            {
                allHash.emplace_back(curHash);
            }
        }
    }

    sort(allHash.begin(), allHash.end());
    allHash.erase(unique(all(allHash)), allHash.end());

    int q;
    cin >> q;
    while (q--)
    {

        ull queryHash = 0;
        for (int i = 1; i <= a; i++)
        {
            string line;
            cin >> line;
            line = ' ' + line;
            for (int j = 1; j <= b; j++)
            {
                queryHash = queryHash * p + int(line[j] - '0');
            }
        }

        if (binary_search(all(allHash), queryHash))
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.