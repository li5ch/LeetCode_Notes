/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         vector<int> m(29);
         int start=0,len=s1.size();
         for(auto c:s1)m[c-'a']++;
         for(int i=0;i<s2.size();i++){
             if(--m[s2[i]-'a']<0){
                 while(++m[s2[start++]-'a']);
             }else if(len+start-1==i)
                return true;

         }
         return false;
    }
};
// @lc code=end

