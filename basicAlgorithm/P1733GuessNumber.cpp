// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ull = unsigned long long;

inline void optimizeIO()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    optimizeIO();

    ll l=1;
    //ll r=1000000001;
    ll r=1e9;//不知道为什么，这个题右边界必须设置为1e9 or 1e9+1,其他边界都不行

    while (l<=r)
    {
        ll mid = (l+r)>>1;
        cout<<mid<<endl;//猜数
        ll res;
        cin>>res;  

        if(res==0){
            return 0;
        }else if(res==1){
            r=mid;
        }else if(res==-1){
            l=mid+1;
        }
        
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.