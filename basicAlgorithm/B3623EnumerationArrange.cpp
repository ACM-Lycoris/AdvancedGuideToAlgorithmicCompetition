// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    vector<int> ans;
    vector<bool> vis(n+1,false);
    auto DFS=[&](auto&& self,int pos,int next) ->void {

        if(pos==k){
            for(int num:ans){
                cout<<num<<' ';
            }
            cout<<endl;
            return ;
        }

        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vis[i]=true;
                ans.push_back(i);
                self(self,pos+1,i);
                vis[i]=false;
                ans.pop_back();//回溯
            }
        }

    };

    DFS(DFS,0,1);

    

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.