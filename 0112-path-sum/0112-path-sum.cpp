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
    bool istrue(TreeNode* root,int targetsum){
        if(!root){
            return false;
        }
        targetsum-=root->val;
        
        if(root->left==NULL&& root->right==NULL){
            if(targetsum==0){
                return true;
            }
            return false;
        }
        
      
        if(istrue(root->left,targetsum)) return true;
     
        
        if(istrue(root->right,targetsum)) return true;
     
      return false; 
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
      
       
        
        return istrue(root,targetSum);
    }
};