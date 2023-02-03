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
#include<queue>
class Solution {
public:
    map <int, priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>> mp;
    void dfs(TreeNode* r, int l, int v)
    {
        if(!r)
            return;
        mp[v].push({l, r->val});
        dfs(r->left, l+1, v-1);
        dfs(r->right, l+1, v+1);
    }
    void bfs(TreeNode*r , int l, int v)
    {
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({r, {0, 0}});
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode* temp = p.first;
            int l = p.second.first, v = p.second.second;
            mp[v].push({l, temp->val});
            if(temp->left)
                q.push({temp->left, {l+1, v-1}});
            if(temp->right)
                q.push({temp->right, {l+1, v+1}});
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* r) 
    {
        vector<vector<int>> res;
        dfs(r, 0, 0);
        //bfs(r, 0, 0);
        for(auto i : mp)
        {
            vector <int> v;
            while(!i.second.empty())
            {
                v.push_back(i.second.top().second);
                i.second.pop();
            }
            res.push_back(v);
        }
        return res;
    }
};
