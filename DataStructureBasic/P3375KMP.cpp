// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(),x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1,s2;
    cin>>s1>>s2;

    int n=s1.length(),m=s2.length();

    s1=' '+s1;
    s2=' '+s2;

    vector<int> Next(m+1);

    for(int i=2,j=0;i<=m;i++){

        while(j && s2[i]!=s2[j+1]){
            j=Next[j];
        }
        if(s2[i]==s2[j+1]){
            j++;
        }
        Next[i]=j;
    }

    for(int i=1,j=0;i<=n;i++){

        while(j && s1[i] !=s2[j+1]){
            j=Next[j];
        }

        if(s1[i]==s2[j+1]){
            j++;
        }
        
        if(j==m){
            cout<<i-m+1<<'\n';
            j=Next[j];//折回，继续匹配下一轮
        }

    }

    for(int i=1;i<=m;i++){
        cout<<Next[i]<<' ';
    }
    cout<<endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.