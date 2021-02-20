/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size(),ans=0;
        vector<int> dp;
        sort(envelopes.begin(),envelopes.end(),[](vector<int> a,vector<int> b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        for(int i=0;i<n;i++){
            auto it=lower_bound(dp.begin(),dp.end(),envelopes[i][1]);
            if(it==dp.end()) dp.push_back(envelopes[i][1]);
            else *it=envelopes[i][1];
        }

        return dp.size();
        
    }
};
// @lc code=end

