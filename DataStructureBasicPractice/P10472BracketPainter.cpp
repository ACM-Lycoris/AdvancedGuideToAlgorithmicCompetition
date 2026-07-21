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

bool Left(const char &c)
{
    if (c == '{' || c == '(' || c == '[')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    optimize();

    string str;
    cin >> str;
    int N = str.length();
    str = ' ' + str;
    stack<int> s; // 栈存下标记

    s.push(0);//很坑的一点是，这里的边界要与1or0 -based搭配
    //如果是0based，需要采取s.push(-1),因为这个边界是要参与计算的
    //例如s="()",算长度就要按边界为0

    auto Match = [&](char c) -> bool
    {
        if (s.size() <= 1)
        {
            return false;
        }

        char left = str[s.top()];

        return (c == ')' && left == '(') ||
               (c == ']' && left == '[') ||
               (c == '}' && left == '{');
    };

    int ans = 0;

    for (int r = 1; r <= N; r++)
    {
        char c = str[r];
        if (Left(c))
        {
            s.push(r);
        }
        else
        {

            // 进入右括号阶段
            if (!s.empty() && Match(c))
            {
                // 合法匹配
                s.pop();
                ans = max(r - s.top(), ans);
            }
            else
            {
                while (!s.empty())
                {
                    s.pop();
                }
                s.push(r);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.