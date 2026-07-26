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
   TreeNode* find(vector<int> &preorder,int &idx,long long upper,long long lower){
    if(idx>=preorder.size()){
        return NULL;
    }
      
   

   
     //left
    if(preorder[idx] >= upper || preorder[idx] <= lower) return NULL;
    TreeNode* root=new TreeNode(preorder[idx]);
      idx++;
    root->left=find(preorder,idx,root->val,lower);
     
     root->right=find(preorder,idx,upper,root->val);

     



return root;
   }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        long long upper=LLONG_MAX;
        long long lower=LLONG_MIN;

        return find(preorder,idx,upper,lower);
    
    }
};