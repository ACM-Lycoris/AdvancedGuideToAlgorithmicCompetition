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

    string line;
    while (cin >> line)
    {
        if (line == "end")
        {
            break;
        }

        vector<vector<bool>> row(10, vector<bool>(10, 0));
        vector<vector<bool>> col(10, vector<bool>(10, 0));
        vector<vector<bool>> grid(10, vector<bool>(10, 0));

        vector<vector<int>> graph(10, vector<int>(10, 0));

        vector<pair<int, int>> emptyPos;

        line = " " + line;

        for (int i = 1; i <= 81; i += 9)
        {
            string curCow = line.substr(i, 9);
            int t = (i - 1) / 9 + 1;
            for (int j = 1; j <= 9; j++)
            {
                if (curCow[j - 1] == '.')
                {
                    graph[t][j] = 0;
                    emptyPos.emplace_back(t, j);
                }
                else
                {
                    int num = curCow[j - 1] - '0';
                    graph[t][j] = num;
                    row[t][num] = 1;
                    col[j][num] = 1;
                    grid[Id(t, j)][num] = 1;
                }
            }
        }

        auto DFS = [&](auto &&self, int pos)
        {
            if (pos >= emptyPos.size())
            {
                return true;
            }

            // P10482卡剪枝
            int best = pos;
            int minCnt = 10;

            for (int i = pos; i < emptyPos.size(); i++)
            {
                auto [x, y] = emptyPos[i];
                int cnt = 0;
                for (int num = 1; num <= 9; num++)
                {
                    if (!row[x][num] && !col[y][num] && !grid[Id(x, y)][num])
                    {
                        cnt++;
                    }
                }
                if (cnt == 0)
                {
                    return false;
                }
                if (cnt < minCnt)
                {
                    minCnt = cnt;
                    best = i;
                }
            }

            swap(emptyPos[pos], emptyPos[best]);

            auto [x, y] = emptyPos[pos];
            for (int num = 1; num <= 9; num++)
            {
                if (!row[x][num] && !col[y][num] && !grid[Id(x, y)][num])
                {
                    graph[x][y] = num;
                    row[x][num] = 1;
                    col[y][num] = 1;
                    grid[Id(x, y)][num] = 1;
                    if (self(self, pos + 1))
                    {
                        return true;
                    }
                    graph[x][y] = 0;
                    row[x][num] = 0;
                    col[y][num] = 0;
                    grid[Id(x, y)][num] = 0;
                }
            }
            return false;
        };

        DFS(DFS, 0);

        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                cout << graph[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}