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

    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();

    string ss1 = s1 + s1;
    string ss2 = s2 + s2;

    string minS1 = "", minS2 = "";

    auto minS = [&](const string &s) -> string
    {
        // 从ss里找最小表示法

        int i = 0;
        int j = 1;
        int k = 0;

        while (i < n && j < n && k < n)
        {

            if (s[i + k] == s[j + k])
            {
                k++;
            }
            else if (s[i + k] > s[j + k])
            {
                i = i + k + 1;
                if (i == j)
                {
                    i++;
                }
                k = 0;
            }
            else if (s[i + k] < s[j + k])
            {
                j = j + k + 1;
                if (i == j)
                {
                    j++;
                }
                k = 0;
            }
        }

        int pos = min(i, j);
        return s.substr(pos, n);
    };

    minS1=minS(ss1);
    minS2=minS(ss2);

    if(minS1==minS2){
        cout<<"Yes\n";
        cout<<minS1<<endl;
    }
    else{
        cout<<"No\n";
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.