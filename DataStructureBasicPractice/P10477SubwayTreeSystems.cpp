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

    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        vector<vector<int>> Tree1(1), Tree2(1);

        auto BuildTree = [&](const string &s, vector<vector<int>> &Tree) -> void
        {
            int cur = 0;
            vector<int> parent(1, -1);
            for (char c : s)
            {
                if (c == '0')
                {
                    int nextNode = Tree.size();
                    Tree.push_back({});
                    // 每一次深走都绝对是新开节点
                    parent.push_back(cur);
                    Tree[cur].push_back(nextNode);
                    cur = nextNode;
                }
                else
                {
                    cur = parent[cur]; // 折返
                }
            }
        };

        BuildTree(s1, Tree1);
        BuildTree(s2, Tree2);

        auto getCode = [&](const vector<vector<int>> &Tree) -> string
        {
            function<string(int)> DFS = [&](int u) -> string
            {
                vector<string> childCodes;

                for (int v : Tree[u])
                {
                    childCodes.push_back(DFS(v));
                }

                sort(all(childCodes));

                string code = "0";

                for (string childCode : childCodes)
                {
                    code += childCode;
                }

                code += "1";

                return code;
            };

            return DFS(0); // 从0开始DFS一次得到字符串
        };

        string res1 = getCode(Tree1);
        string res2 = getCode(Tree2);

        if (res1 == res2)
        {
            cout << "same\n";
        }
        else
        {
            cout << "different\n";
        }
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.