/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int tot=0,mx=0,start=0;
        for(int i=n-1;i>=0;i--){
            tot+=gas[i]-cost[i];
            if(tot>=mx){
                mx=tot;
                start=i;
            }
        }
        return tot>=0?start:-1;
    }
};
// @lc code=end

