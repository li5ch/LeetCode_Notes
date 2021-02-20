/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int dp = 0,pre = INT_MAX;
        int ans=0;
        for(int i=1;i<A.size();i++){
            if(A[i]-A[i-1]==pre){
                if(++dp>=3){
                    ans+=dp-2;
                }
            }else{
                pre=A[i]-A[i-1];
                dp=2;
            }
        }
        return ans;
    }
};
// @lc code=end

