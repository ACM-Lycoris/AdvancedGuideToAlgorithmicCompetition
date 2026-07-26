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

using Course = tuple<ll, ll, ll>; // 每一个进程，申请时间，内存，耗时
using Runing = tuple<ll, ll, ll>; // 运行中进程的结束时间，内存左右端点

int main()
{
    optimize();

    ll N;
    cin >> N;

    vector<Course> Courses;
    set<pair<ll, ll>> FreeMem; // 当前所有的空闲内存的左右端点
    FreeMem.insert({0,N-1});

    ll T, M, P;
    while (cin >> T >> M >> P)
    {
        if (T == 0 && M == 0 && P == 0)
        {
            break;
        }
        Courses.emplace_back(T, M, P);
    }

    auto Merge = [&](ll L, ll R) -> void
    {
        // 程序结束时释放内存

        auto Right = FreeMem.lower_bound({L, LLONG_MIN});
        // 第一个比L大的右区间
        if (Right != FreeMem.begin())
        {
            // 左侧有东西
            auto Left = prev(Right);
            if (Left->second == L - 1)
            {
                L = Left->first;
                FreeMem.erase(Left);
            }
        }

        if (Right != FreeMem.end() && Right->first == R + 1)
        {
            R = Right->second;
            FreeMem.erase(Right);
        }

        FreeMem.insert({L, R});
    };

    auto allocate = [&](const ll &M) -> pair<ll, ll>
    {
        for (auto it = FreeMem.begin(); it != FreeMem.end(); it++)
        {
            ll L = it->first, R = it->second;

            ll len = R - L + 1;
            if (len >= M)
            {

                if (len > M)
                {
                    ll newL = L + M; // 如果长度够，内存就要重新分配
                    FreeMem.insert({newL, R});
                }
                FreeMem.erase(it);
                return {L, L + M - 1};
            }
        }
        // 转了一圈没找到
        return {-1, -1};
    };

    ll finalTime = 0;//pq中存的是结束时间，用这个来处理
    ll WaitCnt = 0;

    priority_queue<Runing, vector<Runing>, greater<Runing>> pq; // 当前运行中的所有进程
    queue<Course> Waiting;                                      // 等待队列



    auto curTime = [&](const ll Time) -> void
    {
        finalTime=Time;
        // 处理当前时间 
        while (!pq.empty() && Time == get<0>(pq.top()))
        {
            // 释放当前所有结束了的内存
            auto [FinTime, L, R] = pq.top();
            pq.pop();
            Merge(L, R);
        }

        while (!Waiting.empty() && get<0>(Waiting.front()) <= Time) // 处理等待队列
        {
            // 尝试分配内存
            auto [L, R] = allocate(get<1>(Waiting.front()));
            if (L == -1 && R == -1)
            {
                break; // 不可僭越队首
            }
            else
            {
                // 其余情况都是找到可分配区间并已经分配
                // 只需要加入运行中队列
                ll FinTime = Time + get<2>(Waiting.front());
                Waiting.pop();
                pq.push(make_tuple(FinTime, L, R));
            }
        }
    };

    for (auto [t, m, p] : Courses)
    {
        // 依次处理
        while(!pq.empty() && get<0>(pq.top()) <= t){
            //当前队列没处理完
            ll now=get<0>(pq.top()); 
            curTime(now);//对这个时间结算
        }

        //再处理这个进程
        auto [L,R] = allocate(m);

        if(L==-1 && R==-1){
            //分配失败,等待队列
            Waiting.push(make_tuple(t,m,p));
            WaitCnt++;
        }
        else{
            pq.push(make_tuple(t+p,L,R));
        }

    }

    while(!pq.empty()){
        curTime(get<0>(pq.top()));
    }

    cout<<finalTime<<'\n';
    cout<<WaitCnt<<'\n';

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.