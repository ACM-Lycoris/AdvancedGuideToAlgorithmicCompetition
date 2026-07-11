// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;
    priority_queue<ll,vector<ll>,less<ll>> Left;//大顶左堆
    priority_queue<ll,vector<ll>,greater<ll>> Right;//小顶右堆
    

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;

        if(Left.empty())Left.push(x);
        else{
            if(Right.empty()){
                Left.push(x);
            }else{
                //左右堆都已经不空，需要判断

                if(x>Right.top()){
                    Right.push(x);
                }else if(x<=Right.top()){
                    Left.push(x);
                }

            }
        }

        if(i&1){
            //为奇数的时候维护并输出一次
            while(Left.size()>Right.size()+1){
                ll bigger = Left.top();
                Right.push(bigger);
                Left.pop();
            }//左维护

            while(Left.size()<Right.size()+1){
                ll smaller = Right.top();
                Left.push(smaller);
                Right.pop();
            }//右维护
            cout<<Left.top()<<'\n';
        }else{
            
        }
        
    }
    

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.