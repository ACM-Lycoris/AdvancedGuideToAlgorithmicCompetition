// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

inline void optimizeIO()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    optimizeIO();

    ll n, m, t;
    cin >> n >> m >> t;

    if (t % n != 0 && t % m != 0)
    {
        while (t--)
        {
            ll a, b;
            cin >> a >> b;
        } // 不做任何处理，仅仅防止编译出错
        cout << "impossible\n"; // 行列都不满足是不能的
    }
    else
    {
        vector<ll> col(n + 1), row(m + 1);
        auto minChangeCnt = [&](ll Len, vector<ll> everyColRow) -> ll { // 传递一个每行或每列有多少摊点的数组
            // Len是决定处理行或列的参数,直接传入n或m

            vector<ll> sPref(Len + 1, 0); // 先构建前缀

            for (int i = 1; i <= Len; i++)
            {
                sPref[i] = sPref[i-1] + everyColRow[i];
            }

            if (sPref[Len] % Len != 0)
            { // sPref[Len]是总数，前缀和的最后一个元素，不能整除长度就返回-1
                return -1;
            }

            ll avg = sPref[Len] / Len;
            vector<ll> cPref(Len + 1, 0); // 偏差前缀和，即这个点离avg差了多少

            for (int i = 2; i <= Len; i++)
            { // 因为是位置i以前的累计偏差，从2开始
                cPref[i] = sPref[i - 1] - (i - 1) * avg;
            }

            sort(cPref.begin() + 1, cPref.end());

            ll median = cPref[(Len + 1) >> 1]; // median就是断环常数

            ll res = 0;
            for (int i = 1; i <= Len; i++)
            {
                res += abs(cPref[i] - median);
            }

            return res;
        };

        while (t--)
        {
            ll x, y;
            cin >> x >> y;
            col[x]++;
            row[y]++;
        }

        ll cCnt = minChangeCnt(n, col);
        ll rCnt = minChangeCnt(m, row);

        if (rCnt == -1)
        { // 列不可行，行可行
            cout << "row " << cCnt << endl;
        }
        else if (cCnt == -1)
        { 
            cout << "column " << rCnt << endl;
        }
        else
        {
            cout << "both " << rCnt + cCnt << endl;
        }
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.