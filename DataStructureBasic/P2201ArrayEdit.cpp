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

    ll n;
    cin >> n;

    stack<ll>  NumsL, NumsR;                 // 光标左右数字栈
    vector<ll> FactPref(1145141, 0);         // 实际前缀和，试验，感觉有点多余
    vector<ll> maxPref(1145141, LLONG_MIN);  // maxPref[i]表示i之前最大的前缀和

    ll j = 0;

    while (n--)
    {
        char op;
        cin >> op;
        if (op == 'I')
        {
            ll Insert;
            cin >> Insert;

              // 插入数字
            NumsL.push(Insert);
            j++;

              // 记录数字
            FactPref[j] = FactPref[j - 1] + Insert;
            maxPref[j]  = max(FactPref[j], maxPref[j - 1]);
        }
        else if (op == 'D')
        {
            NumsL.pop();
            j--;
        }
        else if (op == 'L')
        {
            ll cur = NumsL.top();
            NumsR.push(cur);
            NumsL.pop();
            j--;
        }
        else if (op == 'R')
        {
            ll cur = NumsR.top();
            NumsL.push(cur);
            NumsR.pop();
            j++;
            FactPref[j] = FactPref[j - 1] + cur;//可能更新
            maxPref[j]  = max(FactPref[j], maxPref[j - 1]);
        }
        else
        {
            ll k;
            cin >> k;
              // 查询最大前缀和
            cout << maxPref[k] << endl;
            
        }
    }

    return 0;
}
  // The answer is in the depth of five fathoms. And has always been her.