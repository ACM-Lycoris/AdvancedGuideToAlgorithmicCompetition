// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S{istreambuf_iterator<char>(cin), istreambuf_iterator<char>()};

    string clean; // 清理干净后的小写字符串
    vector<int> pos;

    ll n = S.length();
    
    for (int i = 0; i < n; i++)
    {
        char c = S[i];
        if (isalpha(c))
        {
            clean.push_back(tolower(c));
            pos.emplace_back(i);
            // 直接为clean放入小写字母
            // pos直接压入i就行
        }
    }

    // 读入完成，Manacher算回文

    auto Manacher = [&]() -> pair<int, int> // 返回最佳中心i与p[i]
    {
        int center = 0;
        int right = 0; // 中心与右边界

        string s = "^#";
        for (char c : clean)
        {
            s += c;
            s += "#";
        }
        s += "$";

        int bestCenter=0;
        int bestLen=0;
        int bestL=INT_MAX;

        vector<int> p(s.length() + 1, 0);
        for (int i = 1; i < int(s.length()) - 1; i++)
        {
            int mirror = 2 * center - i;

            if(i < right){
                p[i] = min(p[mirror], right - i);
            }

            while (s[i - p[i] - 1] == s[i + p[i] + 1])
            {
                // 扩展
                p[i]++;
            }
            if (p[i] + i > right)
            {
                // 更优化方案
                center = i;
                right = i + p[i];
            }
            
            int curL = (i - p[i]) / 2;

            if (p[i] > bestLen ||
                (p[i] == bestLen && curL < bestL))
            {
                bestLen = p[i];
                bestCenter = i;
                bestL=min(curL,bestL);//左边界
            }

        }

        return {bestCenter, bestLen};
        // 对应找到的最佳i,p[i]
    };

    auto [i, pi] = Manacher();

    int L = (i - pi) / 2;
    int Len = pi;
    int R = L + Len - 1;
    // 在clean中对应最长回文子串的左右边界与长度

    cout << Len << endl;

    int Left = pos[L];
    int Right = pos[R];
    for (int j = Left; j <= Right; j++)
    {
        cout << S[j];
    }

    return 0;
}