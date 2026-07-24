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

    TreeNode* helper(TreeNode* root,int key){
        if(root->left==NULL){
            return root->right;
        }
        else if(root->right==NULL){
            return root->left;
        }
        else{
            TreeNode* leftchild=root->left;
            //last child in right direction
            TreeNode* lastchild=last(root->left);
            lastchild->right=root->right;
            return leftchild;
        }
        return NULL;
    }
    TreeNode* last(TreeNode* root){
        while(root->right){
            root=root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val==key){
            return helper( root,key);
        }
        TreeNode* dup=root;
        while(root){
            
            if(root->left&&root->left->val==key){
                root->left=helper(root->left,key);
                break;
            }
            else if(root->val>key){
                root=root->left;
            }
            else if(root->right&&root->right->val==key){
                root->right=helper(root->right,key);
                break;
            }
           else{
                root=root->right;
            }



        }

 return dup;
    }
};