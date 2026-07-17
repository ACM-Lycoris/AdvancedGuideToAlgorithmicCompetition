// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

const int N = 1e5 + 5;
int son[N * 31][2]; // 每个整数需要31位，也就是31*N个节点
int idx;
void Insert(const int &a)
{
    int u = 0;
    for (int i = 30; i >= 0; i--)
    {
        int bit = (a >> i) & 1;
        if (son[u][bit] == 0)
        {
            son[u][bit] = ++idx;
        }
        u = son[u][bit];
    }
}

int queryMaxXOR(const int &a)
{
    int u = 0;
    int ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        int bit = (a >> i) & 1;
        int want = bit ^ 1;

        if (son[u][want] != 0)
        {
            ans |= (1 << i);
            u = son[u][want];
        }
        else
        {
            // 相反位不在，只能走相同位，然后走相同位ans不变
            u = son[u][bit];
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        Insert(x);
    }

    int ans = 0;

    for (int x : a)
    {
        ans = max(ans, queryMaxXOR(x));
    }

    cout << ans << endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.