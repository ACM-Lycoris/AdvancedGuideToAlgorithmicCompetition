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

    int T;
    cin >> T;
    const int MAXN = 1e5+10;
    int n;
    vector<string> phoneList;

    vector<vector<int>> son(MAXN, vector<int>(10, 0));
    vector<int> passCnt(MAXN, 0); // 路过此节点的个数
    vector<int> endCnt(MAXN, 0);  // 以此节点结束的个数

    int idx = 0;

    auto Insert = [&](const string &s) -> void
    {
        int p = 0;

        for (char c : s)
        {
            int num = c - '0';
            if (son[p][num] == 0)
            {
                son[p][num] = ++idx;
            }
            p = son[p][num];
            passCnt[p]++;
        }
        endCnt[p]++;
    };

    auto CheckPref = [&](const string &s) -> bool
    {
        // 检查这个字符串是否是前缀

        int p = 0;

        for (char c : s)
        {
            int num = c - '0';
            p = son[p][num];
        }
        // 如果能坚持走完

        if(passCnt[p]>endCnt[p]){
            return false;
        }else{
            return true;
        }

    };

    while (T--)
    {
        cin >> n;

        phoneList.assign(n+1,"");
        son.assign(MAXN, vector<int>(10, 0));
        passCnt.assign(MAXN,0);
        endCnt.assign(MAXN,0);
        idx=0;

        for(int i=1;i<=n;i++){
            string curNum;
            cin>>curNum;
            phoneList[i]=curNum;
            Insert(curNum);
        }

        bool ok=true;
        for(int i=1;i<=n;i++){
            if(!CheckPref(phoneList[i])){
                ok=false;
                break;
            }
        }

        if(!ok){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }

    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.