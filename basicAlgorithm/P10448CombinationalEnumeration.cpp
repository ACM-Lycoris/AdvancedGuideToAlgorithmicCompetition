// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int n, m;
vector<int> path;

void DFS(int pos, int start)
{
    if (pos == m)
    {
        for(int num:path){
            cout<<num<<" ";
        }
        cout<<endl;
        return;
    }

    for (int i = start; i <= n; i++)
    {
        path[pos] = i;
        DFS(pos + 1, i + 1);
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m;
    path.resize(m);
    DFS(0, 1);


    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.