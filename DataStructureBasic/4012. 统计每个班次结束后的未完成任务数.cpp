#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> countTasks(vector<int> &tasks, vector<int> &shifts)
    {
        vector<int> res;

        int n = tasks.size();
        vector<int> Pref(n + 1, 0);
        Pref[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            Pref[i] = Pref[i - 1] + tasks[i - 1];
        }

        long long lastTime = 0;

        for (int num : shifts)
        {

            lastTime += num;

            // 对于每个班次
            if (lastTime >= Pref[n])
            {
                // 能全部做完
                lastTime = 0;
                res.emplace_back(0);
                continue;
            }

            auto it = upper_bound(Pref.begin(), Pref.end(), lastTime);

            int id = it - Pref.begin();

            res.emplace_back(n - id + 1);
        }

        return res;
    }
};
// @lc code=end
