/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> pa(n);
        int mx=1,mx_idx=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0&&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    pa[i]=j;
                    if(mx<dp[i]){
                    mx=dp[i];mx_idx=i;
                }
                }                                        
            }
        }
        for(int i=0;i<mx;i++){
            ans.push_back(nums[mx_idx]);
            mx_idx=pa[mx_idx];
        }
        return ans;
    }
};
// @lc code=end

