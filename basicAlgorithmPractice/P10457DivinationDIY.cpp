// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int val(char c)
{
    if (c == 'A')
        return 1;
    if (c >= '2' && c <= '9')
        return c - '0';
    if (c == '0')
        return 10;
    if (c == 'J')
        return 11;
    if (c == 'Q')
        return 12;
    return 13; // K
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> Pockers(14, vector<int>(4));
    for (int i = 1; i <= 13; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            char c;
            cin >> c;
            Pockers[i][j] = val(c);
        }
    }

    vector<int> pos(14, 3); // 每堆牌最底下还没有被抽到的位置
    vector<int> cnt(14, 0); // 每种牌被翻开几次

    for (int i = 0; i < 4; i++)
    {
        // 四条命，最多循环四次
        int cur = Pockers[13][i];

        while (cur != 13)
        {                                 // 依据规则，不能抽到13
            cnt[cur]++;                   // 抽到一次
            int old = cur;                // 暂存
            cur = Pockers[cur][pos[cur]]; // 把这张牌翻出来
            pos[old]--;                   // 这里的被抽到
        }
    }
    int ans = 0;
    for (int i = 1; i <= 12; i++)
    {
        if (cnt[i] == 4)
        {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.