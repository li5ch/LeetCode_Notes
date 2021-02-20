/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root||(!root->left&&!root->right)) return 0;
        stack<TreeNode*> q;
        q.push(root);int ans=0;
        while(!q.empty()){
            auto u=q.top();
            q.pop();
            if(u->left&&!u->left->left&&!u->left->right) ans+=u->left->val;
            if(u->left) q.push(u->left);
            if(u->right) q.push(u->right);

            
        }
        return ans;
    }
    
};
// @lc code=end

