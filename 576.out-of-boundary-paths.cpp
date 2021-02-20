/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        typedef long long ll;
        for(int k=1;k<=N;k++){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    ll u= i==0?1:dp[k-1][i-1][j];
                    ll d= i==m-1?1:dp[k-1][i+1][j];
                    ll l= j==0?1:dp[k-1][i][j-1];
                    ll r= j==n-1?1:dp[k-1][i][j+1];
                    dp[k][i][j]=(u+d+r+l)%1000000007;
                }
            }
        }
        return dp[N][i][j];
    }
};
// @lc code=end

