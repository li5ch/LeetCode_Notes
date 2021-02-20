    /*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long l=0,r=0;
        for(auto n:nums)l=max(n,(int)l),r+=n;
        while(l<r){
            long long mid=(l+r)/2;
            if(check(nums,mid,m)) r=mid;
            else l=mid+1;
        }
        return l;

    }
    bool check(vector<int>& nums,int sum,int m){
        long long cnt=1,cur=0;
        for(auto n:nums){
            cur+=n;
            if(cur>sum)cur=n,cnt++;
            if(cnt>m) return false;
        }
        return true;
    }
};
// @lc code=end

