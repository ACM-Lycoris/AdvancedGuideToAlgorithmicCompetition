// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    s = ' ' + s; // 1-based

    vector<int> sa(n + 1);      // sa[排名] = 后缀起点
    vector<int> rk(n + 1);      // rk[后缀起点] = 当前排名
    vector<int> newRk(n + 1);   // 新一轮排名
    vector<int> id(n + 1);      // 按第二关键字排好的后缀起点
    vector<int> cnt(max(n, 256) + 1);

    int m = 255;

    // 初始化：rk[i] 暂时存字符 ASCII
    for (int i = 1; i <= n; i++)
    {
        rk[i] = (unsigned char)s[i];
    }

    // 第一次计数排序：按照单个字符排序
    for (int i = 1; i <= n; i++)
    {
        cnt[rk[i]]++;
    }

    for (int i = 1; i <= m; i++)
    {
        cnt[i] += cnt[i - 1];
    }

    // 倒序放置，保证稳定性
    for (int i = n; i >= 1; i--)
    {
        sa[cnt[rk[i]]--] = i;
    }

    for (int len = 1; len < n; len <<= 1)
    {
        int p = 0;

        for (int i = n - len + 1; i <= n; i++)
        {
            id[++p] = i;
        }

        for (int i = 1; i <= n; i++)
        {
            if (sa[i] > len)
            {
                id[++p] = sa[i] - len;
            }
        }

        // 清空当前排名范围内的计数
        fill(cnt.begin(), cnt.begin() + m + 1, 0);

        // 统计第一关键字 rk[id[i]]
        for (int i = 1; i <= n; i++)
        {
            cnt[rk[id[i]]]++;
        }

        // 前缀和
        for (int i = 1; i <= m; i++)
        {
            cnt[i] += cnt[i - 1];
        }

        for (int i = n; i >= 1; i--)
        {
            int x = id[i];
            sa[cnt[rk[x]]--] = x;
        }

        // 根据排好的二元组重新分配排名
        int rankCnt = 1;
        newRk[sa[1]] = 1;

        for (int i = 2; i <= n; i++)
        {
            int x = sa[i - 1];
            int y = sa[i];

            // x、y 的第二关键字
            int rankX =
                (x + len <= n ? rk[x + len] : 0);

            int rankY =
                (y + len <= n ? rk[y + len] : 0);

            // 二元组不同，产生新排名
            if (rk[x] != rk[y] || rankX != rankY)
            {
                rankCnt++;
            }

            newRk[y] = rankCnt;
        }

        // 新排名覆盖旧排名
        rk.swap(newRk);

        // 下一轮 rk 的最大值是 rankCnt
        m = rankCnt;

        // 所有后缀已经完全区分
        if (rankCnt == n)
        {
            break;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << sa[i] << ' ';
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.