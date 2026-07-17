#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

// @lc code=start
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[&](const vector<int> &a,const vector<int> &b){
            int durA=a[0],ddlA=a[1];
            int durB=b[0],ddlB=b[1];
            return ddlA<ddlB;
        });

        int cnt=0;
        int curCostTime=0;
        priority_queue<int,vector<int>,less<int>> pq;
        //大根
        for(vector<int> a:courses){
            int dur=a[0],ddl=a[1];

            //放入
            cnt++;
            curCostTime+=dur;
            pq.push(dur);

            if(curCostTime>ddl){
                curCostTime-=pq.top();
                cnt--;
                pq.pop();
            }
        }
        return cnt;

    }
};
// @lc code=end

