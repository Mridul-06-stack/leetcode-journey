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
  void  mark_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent){
      queue<TreeNode*> q1;
      q1.push(root);
      while(!q1.empty()){
          int size=q1.size();
          for(int i=0;i<size;i++){
              TreeNode* el=q1.front();
              q1.pop();
              if(el->left){
                  q1.push(el->left);
                  parent[el->left]=el;
              }
              if(el->right){
                  q1.push(el->right);
                  parent[el->right]=el;
              }
              
              
              
          }
      }
      return;
  }
  
  void  preorder(TreeNode*root,TreeNode* &k,int target){
      if(!root||k!=NULL){
          return;
      }
      if(root->val==target){
          k=root;

          return;
          
      }
      preorder(root->left,k,target);
      preorder(root->right,k,target);
      return;
  }
    int amountOfTime(TreeNode* root, int start) {
        int target=start;
          unordered_map<TreeNode*,TreeNode*> parent;
        mark_parent(root,parent);
        unordered_map<TreeNode*, bool> visited;
        queue< TreeNode*> q1;
       
        
        
        TreeNode* k=NULL;
        preorder( root,k,target);
        q1.push(k);
        visited[k] = true;
        int count = 0;
         while (!q1.empty()) {
            int size = q1.size();
            
            for (int i = 0; i < size; i++) {
            TreeNode* el = q1.front();
                q1.pop();
                if (el->left && !visited[el->left]) {
                    q1.push(el->left);
                    visited[el->left] = true;
                }
                if (el->right && !visited[el->right]) {
                    q1.push(el->right);
                    visited[el->right] = true;}

                    if (parent[el] && !visited[parent[el]]) {
                        q1.push(parent[el]);
                        visited[parent[el]] = true;
                    }
                    
                }count++;
            }
            
            return count-1;
    }
};