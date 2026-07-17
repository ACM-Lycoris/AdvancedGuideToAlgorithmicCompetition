#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1642 lang=cpp
 *
 * [1642] 可以到达的最远建筑
 */

// @lc code=start
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = heights.size();

        for (int i = 0; i < n - 1; i++) {
            int diff = heights[i + 1] - heights[i];

            if (diff <= 0) {
                continue;
            }
            pq.push(diff);

            if ((int)pq.size() > ladders) {
                bricks -= pq.top();
                pq.pop();
            }

            if (bricks < 0) {
                return i;
            }
        }

        return n - 1;
    }
};
// @lc code=end

