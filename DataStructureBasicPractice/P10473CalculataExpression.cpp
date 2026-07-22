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
int pos; // 当前未处理的最后一个位置
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

ll Expression(); // 加减
ll Mult();       // 乘除
ll PosNeg();     // 处理正负
ll Pow();        // 处理乘方
ll Read();       // 读取数据

ll Expression()
{
    ll left = Mult();
    ll right = 0;

    while(pos<n && (s[pos]=='+' || s[pos]=='-')){
        char op=s[pos];
        pos++;

        right=Mult();

        if(op=='+'){
            left+=right;
        }else if(op=='-'){
            left-=right;
        }

    }

    return left ;
}

ll Mult()
{
    ll left = PosNeg();
    ll right;

    while(pos<n && (s[pos]=='*' || s[pos]=='/')){
        char op=s[pos];
        pos++;

        ll right = PosNeg();

        if(op=='*'){
            left*=right;
        }else if(op=='/'){
            left/=right;   
        }

    }

    return left;
}

ll PosNeg()
{
    // 处理正负号

    if (pos < n && s[pos] == '+')
    {
        pos++;
        return PosNeg();
    }
    else if (pos < n && s[pos] == '-')
    {
        pos++;
        return -PosNeg();
    }

    return Pow();
}

ll Pow()
{
    // 乘方处理
    ll left = Read(); // 要先读取左边
    if ( pos < n && s[pos] == '^' )
    { // 右边如果有多个乘方，要先递归处理完右边
        pos++;
        ll right = Pow(); // 右边有东西才有right
        ll ans = qpow(left, right);
        return ans;
    }
    else
    {
        return left; // 右边没有乘方，就意味着乘方到了最右侧，这时候返回刚刚读进去的，最右侧的"left"即可
    }
}

ll Read()
{
    // 读取数据
    if (pos < n && s[pos] == '(')
    { // 如果是括号就跳过括号继续读
        pos++;
        ll val = Expression();//读取完整表达式
        pos++; // 跳过左右括号
        return val;
    }
    // 不是括号就正常读数字即可

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
    n = s.length();
    pos = 0;
    cout << Expression() << endl;

    return 0;
}