/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty()&&i>=k&&nums[i-k]==dq.front()) dq.pop_front();
            while(!dq.empty()&&nums[i]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            if(i>=k-1) ans.push_back(dq.front());
        }
        return ans;
    }

};
// @lc code=end

