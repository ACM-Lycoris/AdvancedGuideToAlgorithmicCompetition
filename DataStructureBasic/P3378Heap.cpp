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

    priority_queue<ll,vector<ll>,greater<ll>> pq;
    int n;
    cin>>n;
    while(n--){
        int op;cin>>op;
        if(op==1){
            int x;
            cin>>x;
            pq.push(x);
        }else if(op==2){
            cout<<pq.top()<<'\n';
        }else{
            if(!pq.empty()){
                pq.pop();
            }
        }
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.