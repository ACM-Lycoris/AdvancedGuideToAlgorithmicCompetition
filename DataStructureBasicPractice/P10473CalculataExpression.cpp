// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline void optimize()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

string s;
int pos; // 当前还没有处理到的第一个位置
int n;   // 字符串长度

ll qpow(ll a, ll b)
{
    // 快速幂预备
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

ll op1();
ll op2();
ll op3();
ll op4();
ll op5();

ll op1()
{ // 基础式子处理

    ll val = op2();

    while (pos < n && (s[pos] == '+' || s[pos] == '-'))
    {
        char op = s[pos];
        pos++;

        ll right = op2();
        if (op == '+')
        {
            val += right;
        }
        else
        {
            val -= right;
        }
    }
    return val;
};

ll op2()
{ // 乘除

    ll val = op3();
    while (pos < n && (s[pos] == '*' || s[pos] == '/'))
    {
        char op = s[pos];
        pos++;

        ll right = op3();
        if (op == '*')
        {
            val *=right;
        }
        else if (op == '/')
        {
            val /= right;
        }
    }

    return val;
}

ll op3()
{ // 一元正负号
    if (pos < n && s[pos] == '+')
    {
        pos++;
        return op3();
    }
    if (pos < n && s[pos] == '-')
    {
        pos++;
        return -op3();
    }
    return op4();
}

ll op4()
{ // 乘方（快速幂应该可以实现,但这里要递归）

    ll left = op5();
    if (pos < n && s[pos] == '^')
    {
        pos++;
        ll right = op4(); // 要先递归右边的
        left = qpow(left, right);
    }
    return left;
}

ll op5()
{
    // 读取数字，括号
    if (s[pos] == '(')
    {
        pos++;
        ll val = op1(); // 计算括号内完整表达式
        pos++;          // 跳过右括号
        return val;
    }

    ll val = 0;
    while (pos < n && isdigit(s[pos]))
    {
        val = val * 10 + (s[pos] - '0');
        pos++;
    }

    return val;
}

int main()
{
    optimize();

    cin >> s;
    pos = 0;
    n = s.length();

    cout<<op1()<<endl;

    return 0;
}