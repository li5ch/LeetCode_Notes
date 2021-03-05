/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence 
 */

// @lc code=start
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }

        }

        int i=m,j=n;
        string ans;
        while(i&&j){
            if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;j--;
            }else if(dp[i-1][j]>dp[i][j-1]){
                ans.push_back(str1[i-1]);
                i--;
            }else{
                ans.push_back(str2[j-1]);
                j--;
            }
        }
        
        while(i){
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j){
            ans.push_back(str2[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

