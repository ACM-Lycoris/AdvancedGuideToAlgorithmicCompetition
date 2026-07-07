// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

struct Node {
    ll t,lv;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin>>n>>m;

    vector<Node> Macs(n),Task(m);
    for(int i=0;i<n;i++){
        cin>>Macs[i].t>>Macs[i].lv;
    }
    for(int i=0;i<m;i++){
        cin>>Task[i].t>>Task[i].lv;
    }

    sort(all(Macs),[&](const Node &a,const Node &b){
        if(a.t!=b.t){
            return a.t>b.t;
        }else{
            return a.lv>b.lv;
        }
    });

    sort(all(Task),[&](const Node &a,const Node &b){
        if(a.t!=b.t){
            return a.t>b.t;
        }else{
            return a.lv>b.lv;
        }
    });

    vector<ll> cnt(114,0);//计数桶,映射等级->对应机器数量

    ll j=0;
    ll ansTask=0,ansMoney=0;
    for(auto &Tk:Task){
        //对每一个任务：把当前时间足够的机器，塞进桶里

        while(j<n && (Macs[j].t>=Tk.t)){
            cnt[Macs[j].lv]++;
            j++;
        }

        for(int i=Tk.lv;i<114;i++){
            if(cnt[i]){
                //有东西
                cnt[i]--;
                ansTask++;
                ansMoney+= 500*Tk.t+2*Tk.lv;
                break;
            }
        }

    }

    cout<<ansTask<<' '<<ansMoney<<endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.