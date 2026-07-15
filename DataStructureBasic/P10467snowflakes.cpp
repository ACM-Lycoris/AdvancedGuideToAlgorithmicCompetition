// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Snow = tuple<int, int, int, int, int, int>;

map<Snow, int> mp;

Snow getUnique(const array<int, 6> &a)
{

    array<int, 6> BestSnow = a;

    for (int i = 0; i < 6; i++)
    {
        // 对每一个起始点
        array<int, 6> cur;
        for (int j = i; j < i + 6; j++)
        {
            // 做一个snow
            int pos = j % 6;
            cur[j-i]=a[pos];
        }
        BestSnow=min(BestSnow,cur);
    }
    
    for (int i = 0; i < 6; i++)
    {
        // 对每一个起始点,反向就业
        array<int, 6> cur;
        for (int j = i; j > i-6; j--)
        {
            // 做一个snow
            int pos = (j+6) % 6;
            cur[i-j]=a[pos];
        }
        BestSnow=min(BestSnow,cur);
    }
    return make_tuple(BestSnow[0],BestSnow[1],BestSnow[2],BestSnow[3],BestSnow[4],BestSnow[5]);
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;
    
    bool Found=false;

    while(n--){
        array<int,6> snow;
        for(int i=0;i<6;i++){
            cin>>snow[i];
        }
        Snow a=getUnique(snow);

        if(mp.count(a)){
            Found=true;
        }
        mp[a]++;
    }

    if(Found){
        cout<<"Twin snowflakes found.\n";
    }else{
        cout<<"No two snowflakes are alike.\n";
    }

    return 0;
}