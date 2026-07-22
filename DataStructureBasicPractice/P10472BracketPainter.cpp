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

    string s;
    cin >> s;
    ll n = s.length();

    stack<int> stk;

    auto Left = [](const char &c) -> bool
    {
        return c == '(' || c == '[' || c == '{';
    };

    auto Match = [&](const char &r) -> bool
    {
        if (stk.empty())
        {
            return false;
        }

        char l = s[stk.top()];

        return ( //左右字符匹配就返回true
            (l == '(' && r == ')')
        ||  (l == '[' && r == ']')
        ||  (l == '{' && r == '}'));
    };

    //处理部分
    stk.push(-1);
    //填入起始长度

    ll maxLen=0;

    for(int i=0;i<n;i++){
        char c=s[i];
        if(Left(c)){
            stk.push(i);
        }else{
            //右括号
            if(Match(c)){
                //如果匹配
                stk.pop();
                ll curLen=i-stk.top();
                maxLen=max(curLen,maxLen);//读取计算长度
            }else{
                //不匹配
                stk.push(i);//填入i作为非法边界值
            }
        }
    }

    cout<<maxLen<<endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.