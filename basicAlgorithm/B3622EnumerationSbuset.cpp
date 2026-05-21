// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;
    auto DFS=[&](auto&& self,ll pos,string s)->void{
        
        if(pos==n+1){
            cout<<s<<endl;
            return;
        }
        
        self(self,pos+1,s+"N");
        self(self,pos+1,s+"Y");

    };

    DFS(DFS,1,"");


    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.