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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        if(p==NULL&& q==NULL){
            return true;
        }
           if(p!=NULL&& q==NULL|| p==NULL&& q!=NULL){
            return false;
        }
        
        q1.push(p);
        q2.push(q);
        while(!q1.empty()&&!q2.empty()){
            int size1=q1.size();
            int size2=q2.size();
            if(size1!=size2)return false;
            for(int i=0;i<size1;i++){
                TreeNode* el1=q1.front();
                q1.pop();
                TreeNode* el2=q2.front();
                q2.pop();
                if(el1->val!=el2->val){
                    return false;
                }
                if(el1->left==NULL&&el2->left!=NULL||el2->left==NULL&&el1->left!=NULL||el1->right==NULL&&el2->right!=NULL||el2->right==NULL&&el1->right!=NULL) return false;
                if(el1->left) q1.push(el1->left);
                if(el1->right) q1.push(el1->right);
                if(el2->left) q2.push(el2->left);
                if(el2->right) q2.push(el2->right);
            }


        }

        if(!q1.empty()||!q2.empty()){
            return false;
        }
   
   return true; }
};