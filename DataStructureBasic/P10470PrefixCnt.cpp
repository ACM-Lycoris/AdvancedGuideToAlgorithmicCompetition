// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

const int N = 1e6 + 5;

int n, m;
int son[N][26];
int passCnt[N];
int endCnt[N];
int idx;

void Insert(const string &s)
{
    int u = 0;

    for (char c : s)
    {
        int to = int(c-'a');
        if (son[u][to] == 0)
        {
            son[u][to] = ++idx;
        }
        u = son[u][to];
        passCnt[u]++;
    }
    endCnt[u]++;
}

int queryCnt(const string &s){
    int u=0;
    int cnt=0;
    for(char c:s){
        int to = int(c-'a');
        if (son[u][to] == 0)
        {
            return cnt;
        }
        u = son[u][to];
        cnt+=endCnt[u];
    }
    return cnt;
}

int queryPref(const string &s)
{

    int u = 0;
    for (char c : s)
    {
        int to = int(c-'a');
        if (son[u][to] == 0)
        {
            return 0;
        }
        u = son[u][to];
    }
    return passCnt[u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    idx=0;

    while (n--)
    {
        string curInsert;
        cin >> curInsert;
        Insert(curInsert);
    }
    while (m--)
    {
        string QueryS;
        cin >> QueryS;
        cout << queryCnt(QueryS)<< '\n';
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.