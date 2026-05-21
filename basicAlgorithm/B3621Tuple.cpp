// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

vector<int> nums;
void DFS(int n,int k,int cur){

    if(cur==n){
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        return;
    }

    for(int v=1;v<=k;v++){
        nums[cur]=v;
        DFS(n,k,cur+1);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    nums.resize(n);
    DFS(n,k, 0);
    

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.