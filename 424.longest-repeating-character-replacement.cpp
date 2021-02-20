/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0,cnt=0,start=0;
        vector<int> m(26);
        for(int i=0;i<s.size();i++){
            m[s[i]-'A']++;
            cnt=max(m[s[i]-'A'],cnt);
            if(i-start+1-cnt>k){
                m[s[start++]-'A']--;
            }
            ans=max(ans,i-start+1);
        }
        return ans;
    }
};
// @lc code=end

