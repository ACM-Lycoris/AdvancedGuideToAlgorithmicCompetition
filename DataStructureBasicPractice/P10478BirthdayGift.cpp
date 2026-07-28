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

    ll len, m;
    cin >> len >> m;
    vector<ll> temp(len + 1);

    ll firstPositive = 0; // 第一个正数出现的点
    ll lastPositive = 0;  // 最后一个正数出现

    for (int i = 1; i <= len; i++)
    {
        cin >> temp[i];
        if (firstPositive == 0 && temp[i] > 0)
        {
            firstPositive = i;
            lastPositive = i;
        }
        if (lastPositive != 0 && temp[i] > 0)
        {
            lastPositive = i;
        }
    }

    if (m == 0)
    {
        // 特判m==0，防止后面麻烦
        cout << 0 << endl;
        return 0;
    } // m==1不用特判


    if (firstPositive == lastPositive)
    { // 特判
        if (temp[firstPositive] > 0)
        {
            cout << temp[firstPositive] << endl;
            return 0;
        }
        else if (temp[firstPositive] == 0)
        {
            cout << 0 << endl;
            return 0;
        }
    }

    // 压缩序列
    vector<ll> a;
    ll curPosSum = 0, curNegSum = 0; // 当前连续正负段之和
    ll Sum = 0;
    ll cnt = 0;                // 最终最大的和以及当前选择的序列个数
    a.emplace_back(1LL << 62); // 左边界哨兵

    for (int i = firstPositive; i <= lastPositive; i++)
    {
        ll x = temp[i];

        if (x == 0)
        {
            continue;
        }

        // 与最后一个有效块同号，合并
        if (a.size() > 1 && ((a.back() > 0) == (x > 0)))
        {
            a.back() += x;
        }
        else
        {
            // 异号，创建新块
            a.emplace_back(x);
        }
    }

    for (int i = 1; i < (int)a.size(); i++)
    {
        if (a[i] > 0)
        {
            Sum += a[i];
            cnt++;
        }
    }

    a.emplace_back(1LL << 62); // 右边界哨兵
    ll n = a.size() - 2;

    // 如果当前段数再M之内，就可以直接跳出
    if (cnt <= m)
    {
        cout << Sum << endl;
        return 0;
    }

    vector<bool> Del(n + 2, false);                                                  // 懒删除标记
    vector<ll> L(n + 2, 0), R(n + 2, 0);                                             // 链表模拟
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; // 做贪心用优先队列
    //{abs(a[id]),id}用绝对值排序，id定正负

    for (int i = 1; i <= n; i++)
    {

        L[i] = i - 1;
        R[i] = i + 1;

        pq.push({llabs(a[i]), i});
    }

    while (!pq.empty() && cnt > m)
    { // 一旦到达m个就停止，因为每一次处理都是损失的
        auto [val, id] = pq.top();
        pq.pop();
        if (Del[id])
        {
            continue;
        }

        // 开始处理当前值

        // 边界特判
        if (L[id] == 0)
        {

            Sum -= val;
            cnt--;
            Del[id] = true;
            ll Rid = R[id];
            Del[Rid] = true;

            if (cnt == m)
            {
                cout << Sum << endl;
                return 0;
            }
            ll RRid = R[Rid];
            L[RRid] = 0;
            R[0] = RRid;
        }
        else if (R[id] == n + 1)
        {
            Sum -= val;
            cnt--;
            Del[id] = true;

            ll Lid = L[id];
            Del[Lid] = true;
            if (cnt == m)
            {
                cout << Sum << endl;
                return 0;
            }

            ll LLid = L[Lid];
            R[LLid] = n + 1;
            L[n + 1] = LLid;
        }
        else
        {
            ll l = L[id], r = R[id];
            Del[l] = Del[r] = true;

            a[id] += a[l] + a[r];
            L[id] = L[l];
            R[id] = R[r];
            R[L[id]] = id;
            L[R[id]] = id;

            Sum -= val;
            cnt--;
            pq.push({llabs(a[id]), id});
        }
    }

    cout << Sum << endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.