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
 bool find(TreeNode* dummy,TreeNode* root,int k){
    if(!root){
        return false;
    }
    int value=k-root->val;
   
    
    if(helper(dummy,root,value))return true;
    if(find(dummy,root->left,k)) return true;
    if(find(dummy,root->right,k))return true;
    return false;
 }
    bool helper(TreeNode* root,TreeNode* dummy, int value){
        if(!root) return false;
        if(dummy!=root&&root->val==value){
            return true;
        }
        if(root->val>value){
         if(helper(root->left,dummy ,value))return true;
        }
        else{
           if( helper(root->right,dummy,value)) return true;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
       
     return find(root,root,k);   
    }
};