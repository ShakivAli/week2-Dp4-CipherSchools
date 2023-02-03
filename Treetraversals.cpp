#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left,*right;
  Node(int x) : data(x) , left(NULL) , right(NULL) {}
};

void preorder(vector<int> &ans,Node *root){
  if(!root) return ;
  ans.push_back(root->data);
  preorder(ans,root->left);
  preorder(ans,root->right);
}
void inorder(vector<int> &ans,Node *root){
  if(!root) return ;
  inorder(ans,root->left);
  ans.push_back(root->data);
  inorder(ans,root->right);
}
void postorder(vector<int> &ans,Node *root){
  if(!root) return ;
  postorder(ans,root->left);
  postorder(ans,root->right);
  ans.push_back(root->data);
}
vector<vector<int>> levelOrder(Node* root){
  queue<Node *> root;
  q.push(root);
  vector<int> ans;
  while(!q.empty()){
   int size = q.size();
   vector<int> temp;
    while(size--){
      Node *front = q.front();
      q.pop();
      temp.push_back(front->data);
      if(front->left) q.push(front->left);
      if(front->right) q.push(front->right);
   }
    ans.push_back(temp);
    temp.clear();
  }
  return ans;
}

int main(){
  Node *root = new Node(0);
  vector<int> ans ;
  preorder(ans,root);
  for(int i : ans) cout<<i<<" ";cout<<endl;
  ans.clear();
  inorder(ans,root);
  for(int i : ans) cout<<i<<" ";cout<<endl;
  ans.clear();
  postorder(ans,root);
  for(int i : ans) cout<<i<<" ";cout<<endl;
  ans.clear();
  vector<int> levelorder = levelOrder(root);
  for(int i : levelorder) cout<<i<<" ";cout<<endl;
}
