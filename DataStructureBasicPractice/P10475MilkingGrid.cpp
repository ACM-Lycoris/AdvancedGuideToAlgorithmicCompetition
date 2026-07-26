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

    int R, C;
    cin >> R >> C;
    vector<string> Row(R + 1); // 行序列
    vector<string> Col(C + 1); // 列序列

    for (int i = 1; i <= R; i++)
    {
        string line;
        cin >> line;
        Row[i] = line;
        for (int j = 1; j <= C; j++)
        {
            Col[j].push_back(Row[i][j-1]);//把第i行第j个字符（0-based:j-1）加到Col[j]
        }
    }

    vector<int> NextRow(R + 1);

    for (int i = 2, j = 0; i <= R; i++)
    {
        while (j && Row[i] != Row[j + 1])
        {
            j = NextRow[j]; // 回退
        }
        if (Row[i] == Row[j + 1])
        {
            j++;
        }
        NextRow[i] = j;
    }

    vector<int> NextCol(C + 1);

    for (int i = 2, j = 0; i <= C; i++)
    {
        while (j && Col[i] != Col[j + 1])
        {
            j = NextCol[j]; // 回退
        }
        if (Col[i] == Col[j + 1])
        {
            j++;
        }
        NextCol[i] = j;
    }

    int minR = R - NextRow[R];
    int minC = C - NextCol[C];

    cout << minR * minC << endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.