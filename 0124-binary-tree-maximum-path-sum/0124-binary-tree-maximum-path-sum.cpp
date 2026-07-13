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
    int  sum(TreeNode * root,int &maxi,int currentsum){
        if(!root) return 0;
        currentsum=root->val;
        

         int leftsum=sum(root->left,maxi,currentsum);
         int rightsum=sum(root->right,maxi,currentsum); 
         maxi=max(maxi,max(currentsum+leftsum,max(currentsum+rightsum,max(currentsum+leftsum+rightsum,currentsum))));
         return max(currentsum,max(currentsum+leftsum,currentsum+rightsum));

    }
    
    int maxPathSum(TreeNode* root) {
        int maxi=root->val;
        int currentsum=0;
    sum(root,maxi,currentsum);
    return maxi;
    }
};