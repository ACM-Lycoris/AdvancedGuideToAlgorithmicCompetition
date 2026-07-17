// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(),x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    int N=T;
    while(T--){
        cout<<"Test case #"<<N-T<<'\n';

        ll n;
        cin>>n;
        string s;
        cin>>s;
        s=' '+s;

        vector<ll> Next(n+1);
        for(int i=2,j=0;i<=n;i++){
            while(j && s[i] != s[j+1]){
                j=Next[j];
            }
            if(s[i]==s[j+1]){
                j++;
            }
            Next[i]=j;
        }

        for(int i=1;i<=n;i++){
            int p=(i-Next[i]);
            if(i%p!=0 || (i%p==0 && i/p<=1)){
                continue;
            }
            if(i%p==0 && i/p>1){
                int k=i/p;
                cout<<i<<' '<<k<<'\n';
            }
        }


        cout<<"\n";
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.