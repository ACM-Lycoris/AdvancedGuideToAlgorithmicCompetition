// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

    ll n;
    cin>>n;
    priority_queue <ll,vector<ll>,greater<ll>> right;
    priority_queue <ll,vector<ll>,less<ll>>    left  ; 
    
    for(int i=1;i<=n;i++){
        ll curX;
        cin>>curX;
        
        if(left.empty()||curX<=left.top()){
            left.push(curX);
        }else{
            right.push(curX);
        }

        if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
        }else if(right.size()>left.size()){
            left.push(right.top());
            right.pop();
        }

        if(i&1){
            cout<<left.top()<<endl;
        }

    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.