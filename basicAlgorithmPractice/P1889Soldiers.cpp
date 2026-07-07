// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    sort(all(x));
    sort(all(y));

    int disY = 0, disX = 0;
    int kY = y[n / 2];

    for (int i = 0; i < n; i++)
    {
        x[i] -= i;
        disY += abs(y[i] - kY);
    }
    sort(all(x));
    int kX = x[n / 2];
    for (int i = 0; i < n; i++)
    {
        disX += abs(x[i] - kX);
    }

    cout << disX + disY << endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.