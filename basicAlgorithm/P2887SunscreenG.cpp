#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll c, L;
    cin >> c >> L;

    vector<pll> cows(c);          // {minSPF, maxSPF}
    for (auto &[mn, mx] : cows) cin >> mn >> mx;

    vector<pll> bottles(L);       // {SPF, count}
    for (auto &[spf, cnt] : bottles) cin >> spf >> cnt;

    sort(cows.begin(), cows.end());        // 奶牛按 minSPF 升序
    sort(bottles.begin(), bottles.end());  // 防晒霜按 SPF 升序

    // 小顶堆：存放「minSPF <= 当前防晒霜SPF」的奶牛的 maxSPF
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    ll res = 0, i = 0;
    for (auto &[spf, cnt] : bottles) {
        while (i < c && cows[i].first <= spf) {  // 满足下界的牛入堆
            pq.push(cows[i].second);
            i++;
        }
        while (!pq.empty() && pq.top() < spf)    // 上界都不够，永久丢弃
            pq.pop();
        while (cnt > 0 && !pq.empty()) {         // 优先服务 maxSPF 最小的牛
            pq.pop();
            res++;
            cnt--;
        }
    }

    cout << res << "\n";
    return 0;
}