/*
 * @lc app=leetcode id=467 lang=cpp
 *
 * [467] Unique Substrings in Wraparound String
 */

// @lc code=start
class Solution {
public: 
    int findSubstringInWraproundString(string p) {
        vector<int> cnt(26);
        int len =0;int ans=0;
        for( int i=0;i<p.size();i++){
            int cur=p[i]-'a';
            if(i&&p[i-1]!=(cur+26-1)%26+'a')len=0;
            if(++len>cnt[cur]){
                ans+=len-cnt[cur];
                cnt[cur]=len;  
            }
        }
        return ans;
    }
};
// @lc code=end

