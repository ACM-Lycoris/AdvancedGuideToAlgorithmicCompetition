// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()
int c, n;

vector<pair<int    , int>> point;  // 存点
vector<int>         xs, ys;        // 离散化排序去重后的点
vector<vector<int>> pref;          // 二维离散前缀和数组

int getID(const vector<int> &v, int x)
{
                                                                  // 在xs或者ys里查某个坐标的对应编号
    int id = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;  // 返回1-based
    return id;
}

int query(int x1, int y1, int x2, int y2)
{
      // 查x1-x2,y1-y2区域内有多少三叶草
    if (x1 > x2 || y1 > y2)
    {
        return 0;  // 这样不合法
    }
    return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
}

bool check(int len)
{

    int cntX = xs.size();
    int cntY = ys.size();

    for (int x = 1; x <= cntX; x++)
    {
        for (int y = 1; y <= cntY; y++)
        {
            int leftX  = xs[x - 1];
            int downY  = ys[y - 1];
            int rightX = leftX + len - 1;
            int topY   = downY + len - 1;

            int rx = upper_bound(xs.begin(), xs.end(), rightX) - xs.begin();
            int ty = upper_bound(ys.begin(), ys.end(), topY) - ys.begin();
              // 表示在离散组里的序号

            int cnt = query(x, y, rx, ty);
            if (cnt >= c)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> n;

    point.reserve(n);

    while (n--)
    {
        int xi, yi;
        cin >> xi >> yi;
        point.emplace_back(xi, yi);
        xs.emplace_back(xi);
        ys.emplace_back(yi);
    }

      // 排序去重
    sort(all(xs));
    sort(all(ys));
    xs.erase(unique(all(xs)), xs.end());
    ys.erase(unique(all(ys)), ys.end());

    // 不同xy的数量，方便初始化前缀和
    int cntX = xs.size(), cntY = ys.size();

    pref.assign(cntX + 1, vector<int>(cntY + 1, 0));

    for (auto &[x, y] : point)
    {
        int xId = getID(xs, x);
        int yId = getID(ys, y);
        pref[xId][yId]++;
    }

    for (int i = 1; i <= cntX; i++)
    {
        for (int j = 1; j <= cntY; j++)
        {
            pref[i][j] += (pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1]);
        }
    } // 前缀和初始化完成

    int lo = 1;
    int hi = max((xs.back() - xs[0]), (ys.back() - ys[0])) + 1;

    while (lo < hi)
    {
        int mid = (hi + lo) >> 1;
        if (check(mid))
        {
            // 可行就缩小
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    int ans = hi;
    cout << ans << '\n';

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.