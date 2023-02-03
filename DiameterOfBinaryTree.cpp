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
    int ans= INT_MIN;
    int solve(TreeNode *root){
        if(!root) return 0;
        int leftans = solve(root->left);
        int rightans = solve(root->right);
        int dia = leftans + rightans  + 1;
        ans = max(ans,dia);
        return max(leftans,rightans)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans-1;
    }
};
