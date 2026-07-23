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
    TreeNode* flat(TreeNode *root){
if(!root||root->left==NULL&&root->right==NULL){
            return root;
        }
     TreeNode* leftone=flat(root->left);
     TreeNode* rightone=flat(root->right);
     TreeNode* temp = root;
root->right=leftone;
    //  TreeNode*bottomone=new TreeNode();
    //  TreeNode*
     root->left=NULL;
while (temp->right) {
    temp = temp->right;
}

temp->right = rightone;
     
   
return root;

    }
    void flatten(TreeNode* root) {
        flat(root);
        return;
    }
};