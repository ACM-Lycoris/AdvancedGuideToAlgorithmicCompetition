// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

char ch(int x)
{
    if (0 <= x && x <= 9)
        return char('0' + x);
    if (10 <= x && x <= 35)
        return char('A' + x - 10);
    return char('a' + x - 36);
}
unordered_map<char, int> NumC;

string convertString(int from, int to, string s)
{
    // 把 from 进制的 s 转为 to 进制

    vector<int> num;

    for (char c : s)
    {
        int val=NumC[c];
        num.emplace_back(val);
    }

    while(!num.empty() && num[0]==0){
        num.erase(num.begin());
    }

    if(num.empty())return "0";

    string ans="";

    while (!num.empty())
    {
        vector<int> Quo;//商数组
        int rem=0;;//余数，用来计算下一位
        bool start=false;//用来判前导0

        for(int x:num){
            int cur=rem*from +x;//进位
            int q=cur/to;//商
            rem=cur%to;
        
            if(q!=0 || start){
                //这时候才能给第一位放东西，在!start且q==0时，q是不能被加入的

                Quo.emplace_back(q);
                start=true;

            }
        }
        ans.push_back(ch(rem));//最后的余数塞进转换后答案
        num=Quo;//被除数变换
    }

    reverse(all(ans));
    return ans;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i <= 9; i++)
    {
        NumC[char(i + '0')] = i;
    }
    for (int i = 0; i < 26; i++)
    {
        char C = 'A' + i;
        char c = 'a' + i;
        NumC[C] = 10 + i;
        NumC[c] = 36 + i;
    }
    while (n--)
    {
        int from,to;string s;
        cin>>from>>to>>s;

        string ans = convertString(from,to,s);

        cout<<from<<' '<<s<<'\n';
        cout<<to<<' '<<ans<<'\n';
        cout<<endl;

    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.