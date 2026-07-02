// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int start = 0;
    for(int i =0 ;i<4;i++){
        string s;
        cin>>s;
        for(int j=0;j<4;j++){
            if(s[j] == '+'){
                start |= 1<<(i*4+j);//压缩读数
            }
        }
    }
    
    vector<int> flip(16);
    for(int i =0 ;i<4;i++)
    {
        for(int j=0;j<4;j++){
            int m = 0;
            for(int k=0;k<4;k++){
                m |= 1<< (i*4+k);
                m |= 1<< (k*4+j);
            }

            flip[i*4+j] = m;

        }
    }


    int best=18;//最好的切换次数，不会超过16次，因为16次以上每一次都是多余且重复的，
    //提前设一个比16大的数字

    int bestMask=0;//

    for(int mask=0;mask<(1<<16);mask++){
        int board = start;
        for(int pos=0;pos<16;pos++){
            if((mask>>pos)&1){
                board^=flip[pos];
            }
        }

        if(board==0){//如果board被清零
            if(__builtin_popcount(mask)<best){
                //
                best=__builtin_popcount(mask);
                bestMask=mask;
            }
        }
    }

    cout<<best<<endl;
    
    for(int i=0;i<16;i++){
        if((bestMask>>i)&1){
            cout<<i/4+1<<" "<<i%4+1<<endl;
        }
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.