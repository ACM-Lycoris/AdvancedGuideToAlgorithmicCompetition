// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    ll n = s.length();
    s = ' ' + s;

    vector<int> sa(n + 1);
    vector<int> rk(n + 1);
    vector<int> newRk(n + 1);
    vector<int> height(n + 1);

    for (int i = 1; i <= n; i++)
    {
        sa[i] = i;
        rk[i] = s[i];
    }

    for (int len = 1; len < n; len <<= 1)
    {

        sort(sa.begin() + 1, sa.end(), [&](const ll &a, const ll &b)
        {
            if (rk[a] != rk[b]){
                return rk[a] < rk[b];
            }
            ll rankA = (a + len <= n ? rk[a + len] : 0);
            ll rankB = (b + len <= n ? rk[b + len] : 0);
            return rankA < rankB;
        });

        //重新分配rank
        newRk[sa[1]]=1;

        ll rankCnt=1;
        for(int i=2;i<=n;i++){
            ll a=sa[i];
            ll b=sa[i-1];

            ll rankA=(a+len<=n ? rk[a+len] : 0);
            ll rankB=(b+len<=n ? rk[b+len] : 0);

            if(rk[a]!=rk[b] || rankA !=rankB){
                rankCnt++;
            }

            newRk[sa[i]]=rankCnt;

        }

        rk.swap(newRk);

        if(rankCnt == n){
            break;
        }

    }

    ll h=0;
    height[0]=0;
    for(int i=1;i<=n;i++){
        if(rk[i]==1){
            //排名第一的后缀串的0
            //height[sa[1]] = 0;
            h=0;
            continue;
        }
        int j=sa[rk[i]-1];

        while(i+h<=n && j+h<=n && s[i+h]==s[j+h]){
            h++;
        }

        height[rk[i]]=h;
        if(h>0)h--;

    }//height按照排名存而不是起始位置

    for (int i = 1; i <= n; i++)
    {
        cout << sa[i] - 1 << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << height[i] << ' ';
    }
    cout << endl;

    return 0;
}