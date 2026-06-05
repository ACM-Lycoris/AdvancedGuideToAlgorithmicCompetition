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

ll CntInv(vector<int> &graph){
    
    int len= graph.size();

    int maxVal= len+1;
    vector<int> Tree(maxVal+5,0);
    
    auto add = [&](int i,int val) -> void {
        for(;i<maxVal;i+= (i&-i)){
            Tree[i]+=val;
        }
    };

    auto prefSum = [&](int id) ->long long {
        ll sum=0;
        for(;id>0;id-=(id&-id)){
            sum+=Tree[id];
        }
        return sum;
    };

    ll result=0;
    for(int i=len-1;i>=0;i--){

        int curVal = graph[i]; //记录当前值
        result+=prefSum(curVal-1);//逆序对不包含自身
        
        add(curVal,1);

    }
    return result;

}

int main()
{
    optimizeIO();

    int n;
    while (cin >> n)
    {

        vector<int> graph1, graph2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int X;
                cin >> X;
                if (X != 0)
                {
                    graph1.emplace_back(X);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int X;
                cin >> X;
                if (X != 0)
                {
                    graph2.emplace_back(X);
                }
            }
        }
        ll cnt1 = CntInv(graph1), cnt2 = CntInv(graph2);
        if(!((abs(cnt1-cnt2))&1)){
            cout<<"TAK\n";
        }else{
            cout<<"NIE\n";
        }

        
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.