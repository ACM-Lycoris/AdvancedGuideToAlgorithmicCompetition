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

bool compare(int a, int b)
{
    cout << "? " << a << ' ' << b << endl;
    bool t;
    cin >> t;
    return t;
}


int main()
{
    optimizeIO();

    int n; 
    cin>>n;
    vector<int> ans;
    ans.push_back(1);

    for(int i=2;i<=n;i++){//i就是当前要操作的元素
        int l=0;int r=ans.size();
        while(l<r){
            int mid=(l+r)>>1;//我们要在位置mid插入i
            if(compare(i,ans[mid])){
                //i<ans[mid]
                r=mid;
            }else{
                l=mid+1;
            }
        }
        ans.insert(ans.begin()+l,i);
    }

    cout<<"! ";
    for(int num:ans){
        cout<<num<<' ';
    }
    cout<<endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.