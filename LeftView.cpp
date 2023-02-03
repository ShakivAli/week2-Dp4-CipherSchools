

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
                queue<pair<Node *,int>> q;
                if(!root) return ans;
                q.push({root,0});
                while(!q.empty()){
                    auto temp=q.front();
                    q.pop();
                    Node * n = temp.first;
                    int lvl=temp.second;
                    if(ans.size()==lvl){
                        ans.push_back(n->data);
                    }
                if(n->left) q.push({n->left,lvl+1});
                if(n->right) q.push({n->right,lvl+1});
                }
                return ans;
}
