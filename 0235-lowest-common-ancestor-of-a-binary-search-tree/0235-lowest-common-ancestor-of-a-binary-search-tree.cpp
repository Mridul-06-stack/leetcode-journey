/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
   void find(TreeNode*root,TreeNode* p,vector<TreeNode*>& ans){
    if(!root)
    {
        return ;
    }
    ans.emplace_back(root);
    if(root==p){
        return ;
    }
    if(root->val>p->val){
        find(root->left,p,ans);
    }
    else{
        find(root->right,p,ans);
    }
    return ;
   }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*>path2;
        find(root,p,path1);
        find(root,q,path2);
        int number=0;
   
     

     find(root,p,path1);
     find(root,q,path2);

        for(int i=0;i<min(path1.size(),path2.size());i++){
            
            if(path1[i]==path2[i]){
                number=i;
                continue;
            }
            else{
                break;
            }number=i;
        }
    return  path2[number];}
};