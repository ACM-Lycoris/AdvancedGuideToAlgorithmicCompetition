// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
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

    int n, l;
    cin >> n >> l;
    long double left = 2010.0, right = 0.0;
    long double eps  = 1e-11;
    //阴间1：long double搭配1e-11才能过

    vector<long double> nums(n + 1);//原数组
    vector<long double> Residual(n + 1, 0.0);//残差数组
    vector<long double> pref(n + 1, 0.0);//前缀和数组

    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        left  = min(left, nums[i]);
        right = max(right, nums[i]);
    }

      // 二分判定函数
    auto check = [&](long double mid) -> bool
    {
        for (int i = 1; i <= n; i++)
        {
            Residual[i] = nums[i] - mid;
        }
        for (int i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + Residual[i];
        }
        long double minPref = 0;          // 当前r-L左边最小前缀和(Pref[0]==0)
        long double maxSum  = -1919810.0;  // 最大字段和
        for (int r = l; r <= n; r++)
        { // 求最大子段和的右边界r，只要存在一个子段和大于0，说明答案小了，
            minPref = min(minPref, pref[r - l]);
            maxSum  = max(maxSum, pref[r] - minPref);
            if (maxSum >0)//是否等于0无所谓
            {
                return true;  // 答案开小了
            }
        }
        return false;  // 答案大了
    };

    long double ans = 0.0;
    while (abs(right - left) > eps)
    {
        long double mid = left+(right-left)/2.0;
        if(check(mid)){
            //答案开小了
            left=mid;
            ans=mid;
        }else{
            right=mid;
        }
    }

    cout<<int(right*1000)<<endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.