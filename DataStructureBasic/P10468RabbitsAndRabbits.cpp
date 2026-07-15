// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll BASE = 131;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;

    ull len= s.length();

    s=" "+s;

    vector<ull> pw(len+1);//131^i
    vector<ull> hash(len+1);//前i个字符的哈希值

    pw[0]=1;hash[0]=0;
    for(ll i=1;i<=len;i++){
        ull val = s[i]-'a'+1;//映射1-26值
        pw[i]=pw[i-1]*BASE;
        hash[i]=hash[i-1]*BASE+val;
    }

    auto getHashVal = [&](ull left,ull right)-> ull{
        ull val = hash[right]-hash[left-1]*pw[right-left+1];
        return val;
    };


    int m;
    cin>>m;
    while(m--){
        ull l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;

        if(r1-l1!=r2-l2){
            cout<<"No\n";
            continue;
        }

        ull val1=getHashVal(l1,r1);
        ull val2=getHashVal(l2,r2);

        if(val1==val2){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }

    }

    return 0;
}