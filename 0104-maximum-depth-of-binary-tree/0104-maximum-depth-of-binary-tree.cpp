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
    void find(TreeNode* root,int idx,int &maxdepth){
        
        if(root==NULL){
            return ;
        }idx++;
        maxdepth=max(idx,maxdepth);
        find(root->left,idx,maxdepth);
        idx--;
        find(root->right,idx,maxdepth);
        idx--;
        
    }
public:
    // int maxDepth(TreeNode* root) {
    //     if(root==NULL){
    //         return 0;
    //     }
    //     int depth=0;
    //     int maxdepth=0;
    //     int idx=0;
    //     find(root,idx,maxdepth);
        int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        // The depth of the current node is 1 + the maximum depth of its deepest child branch
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    // }
    }
};