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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root ) return false;
        queue<TreeNode*> q1;
        q1.push(root);
        bool flag1=false;
        bool flag2=false;
        while(!q1.empty()){
            int size=q1.size();
            flag1=false;
            flag2=false;
            for(int i=0;i<size;i++){
                TreeNode* el=q1.front();
                q1.pop();
                if(el->val==x) flag1=true;
                if(el->val==y) flag2=true;
                 if (el->left && el->right) {
                    int l = el->left->val;
                    int r = el->right->val;

                    if ((l == x && r == y) || (l == y && r == x))
                        return false;
                }

               if(el->left) q1.push(el->left);
               if(el->right) q1.push(el->right);
                  if(flag1&&flag2) return true;



            }
        }
    
    return false;}
};