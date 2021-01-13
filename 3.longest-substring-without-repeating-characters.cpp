/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(130);
        int ans=0,start=0;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            while(m[s[i]]>1){         
                m[s[start]]--;start++;
            }
            ans=max(i-start+1,ans);
        }
        return ans;
        
    }
};

// @lc code=end

