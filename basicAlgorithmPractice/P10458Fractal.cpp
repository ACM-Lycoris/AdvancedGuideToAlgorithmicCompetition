// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
inline void optimize()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

using ll = long long;

vector<string> graph;
vector<ll> pow3(10);

void draw(int level,int x,int y){

    if(level==1){
        graph[x][y]='X';
        return;
    }

    ll s=pow3[level-2];//3^(lv-2);

    draw(level-1, x,     y);
    draw(level-1, x,     y+2*s);
    draw(level-1, x+s,   y+s);
    draw(level-1, x+2*s, y);
    draw(level-1, x+2*s, y+2*s);

}

int main() 
{
    optimize();
    
    pow3[0]=1;pow3[1]=3;
    for(int i=2;i<10;i++){
        pow3[i]=pow3[i-1]*3;
    }

    int n;
    while(cin>>n){
        if(n==-1){
            break;
        }else{

            graph.assign(pow3[n-1]+1,string(pow3[n-1]+1,' '));
            draw(n,1,1);

            for(ll i=1;i<=pow3[n-1];i++){
                cout<< graph[i].substr(1, pow3[n - 1]) <<endl;;
            }

            cout<<"-\n";

        }
    }

    return 0;
}

// The answer is in the depth of five fathoms. And has always been her.