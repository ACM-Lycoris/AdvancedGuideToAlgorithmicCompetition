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

int pos(const int &x, const int &y)
{
    return (x - 1) * 9 + y;
}

int Id(const int &x, const int &y)
{
    return ((x - 1) / 3 * 3 + (y - 1) / 3 + 1); // 返回九宫格的编号
}

int main()
{
    optimize();

    int T;
    cin >> T;
    while (T--)
    {
        vector<vector<int>> graph(10, vector<int>(10, 0));

        vector<vector<bool>> row(10, vector<bool>(10, 0));
        vector<vector<bool>> col(10, vector<bool>(10, 0));
        vector<vector<bool>> grix(10, vector<bool>(10, 0));

        vector<pair<int, int>> emptyPos;

        for (int i = 1; i <= 9; i++)
        {
            string line;
            cin >> line;
            for (int j = 1; j <= 9; j++)
            {
                int num = line[j - 1] - '0';

                graph[i][j] = num;
                if (num == 0)
                {
                    emptyPos.emplace_back(i, j);
                }
                row[i][num] = 1;
                col[j][num] = 1;
                grix[Id(i, j)][num] = 1;
            }
        }

        function<bool(int)> DFS = [&](int pos) -> bool
        {
            if (pos >= (int)emptyPos.size())
            {
                return true;
            }

            auto [x, y] = emptyPos[pos];

            for (int num = 1; num <= 9; num++)
            {
                if (!row[x][num] && !col[y][num] && !grix[Id(x, y)][num])
                {
                    row[x][num] = 1;
                    col[y][num] = 1;
                    grix[Id(x, y)][num] = 1;
                    graph[x][y] = num;

                    if (DFS(pos + 1))
                    {
                        return true;
                    }

                    graph[x][y] = 0;
                    row[x][num] = 0;
                    col[y][num] = 0;
                    grix[Id(x, y)][num] = 0;
                }
            }
            return false; // 此位置直接不合法
        };

        DFS(0);
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                cout << graph[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}