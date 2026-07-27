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
     void find(TreeNode* root,vector<int> &ans){
        if(!root){
            return;
        }
        ans.emplace_back(root->val);
        find(root->left,ans);
        find(root->right,ans);
        return ;
     }
     void fix (TreeNode* root,int &idx,vector<int> &ans ){
    if(!root||(idx>=ans.size())){
        return ;
    }
    fix(root->left,idx,ans);
    root->val=ans[idx];
    idx++;
    fix(root->right,idx,ans);
    return ;
     }
    void recoverTree(TreeNode* root) {
        vector<int> ans;
        find(root,ans);
        sort(ans.begin(),ans.end());
        int idx=0;
        fix(root,idx,ans);
        
    }
};