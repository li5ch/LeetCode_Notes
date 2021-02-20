/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n=nums.size();
        vector<int> p(n,1);
        vector<int> q(n,1);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]) p[i]=max(q[j]+1,p[i]);
                if(nums[i]<nums[j]) q[i]=max(p[j]+1,q[i]);
            }
        }
        return max(p[n-1],q[n-1]);
    }
};
// @lc code=end

