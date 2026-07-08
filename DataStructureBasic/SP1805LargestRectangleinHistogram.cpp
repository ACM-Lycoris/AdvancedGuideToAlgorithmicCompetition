// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }

        vector<ll> nums(n + 2);

        nums[0] = 0; // 左哨兵

        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
        }

        nums[n + 1] = 0; // 右哨兵，强制清空栈

        stack<int> High; // 存下标，不是存高度
        High.push(0);

        ll ans = 0;

        for (int i = 1; i <= n + 1; i++)
        {
            while (nums[High.top()] > nums[i])
            {
                int cur = High.top();
                High.pop();

                ll height = nums[cur];
                ll width = i - High.top() - 1;

                ans = max(ans, height * width);
            }

            High.push(i);
        }

        cout << ans << '\n';
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.