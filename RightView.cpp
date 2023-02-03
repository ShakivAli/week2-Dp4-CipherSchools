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
    map<int,int> mp;
    void solve(TreeNode *root,int level){
        if(!root) return ;
        mp[level] = root->val;
        solve(root->left,level+1);
        solve(root->right,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        solve(root,0);
        vector<int> ans;
        for(auto iter : mp) ans.push_back(iter.second);
        return ans; 
    }
};
