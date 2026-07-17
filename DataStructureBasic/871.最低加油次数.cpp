#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=871 lang=cpp
 *
 * [871] 最低加油次数
 */

// @lc code=start
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int cnt=0;
        int curRemain=startFuel;
        int n=stations.size(); 
        if(stations.empty()){//没有加油站
            if(startFuel-target>=0){
                return 0;
            }else{
                return -1;
            }
        }
        sort(stations.begin(),stations.end(),[&](const vector<int> &a,const vector<int> &b){
            int posA=a[0],fuelA=a[1];
            int posB=b[0],fuelB=b[1];

            if(posA!=posB){
                return posA<posB;
            }else{
                return fuelA>fuelB;
            }

        });

        priority_queue<int, vector<int>, less<int>> pq;//贪心不选堆

        int lastPoint=0;
        for(int i=0;i<n;i++){

            int curPos=stations[i][0],curFuel=stations[i][1];
            curRemain-=(curPos-lastPoint);
            lastPoint=curPos;
            pq.push(curFuel);//先不选

            if(curRemain<0){
                return -1;
            }else{
                
                if( (i!=n-1 &&  curRemain-(stations[i+1][0]-curPos)<0) 
                ||  (i==n-1 && (curRemain-(target-stations[i][0]))<0 ) ){
                    //不够前往下一站或者最后一站不够达到目的地，尝试加油
                    bool couldContinue=false;
                    int nextCost = (i!=n-1 ? (stations[i+1][0]-curPos):(target-stations[i][0]) );

                    while(!pq.empty() && curRemain-nextCost<0){
                        curRemain+=pq.top();//选最大的一个
                        pq.pop();
                        cnt++;
                        if(curRemain-nextCost>=0){
                            couldContinue=true;
                            break;
                        }
                    }

                    if(!couldContinue){
                        return -1;
                    }
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

