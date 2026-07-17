// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

const int N = 3e6 + 5;

int son[N][62];
int passCnt[N];

int idx; // 当前最后的节点编号

int toNum(const char &c)
{
    if (isalpha(c))
    {
        if (islower(c))
        {
            return int(c - 'a');
        }
        else
        {
            return int(c - 'A' + 26);
        }
    }
    if (isdigit(c))
    {
        return int(c - '0' + 52);
    }
}

void Insert(const string &s)
{
    int u = 0;
    for (char c : s)
    {
        int to = toNum(c);
        if (son[u][to] == 0)
        {
            son[u][to] = ++idx;
        }
        u = son[u][to];
        passCnt[u]++;
    }
    // endCnt[u]++;
}

int queryPrefix(const string &t)
{

    int u = 0;
    // 共有多少Sj，满足t是Sj的前缀
    for (char c : t)
    {
        int to = toNum(c);
        if (son[u][to] == 0)
        {
            return 0;
        }
        else
        {
            u = son[u][to];
        }
    }
    return passCnt[u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;
    while (T--)
    {
        
        int n, q;
        cin >> n >> q;

        for(int u=0;u<=idx;u++){
            memset(son[u],0,sizeof(son[u]));
            passCnt[u]=0;
        }

        idx=0;


        while (n--)
        {
            string curS;
            cin >> curS;
            Insert(curS);
        }

        while (q--)
        {
            string queryS;
            cin >> queryS;
            cout << queryPrefix(queryS) << '\n';
        }
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.