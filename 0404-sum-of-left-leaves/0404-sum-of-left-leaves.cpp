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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root->left && !root->right){
            return 0;
        }
    queue<TreeNode*> q1;
    q1.push(root);
    int level=0;
    int sum=0;
    vector<int>ans;
    while(!q1.empty()){
    TreeNode* el= q1.front();
    q1.pop();
   

   if(el->left) {
    if(el->left->left==NULL && el->left->right==NULL){
        sum+=el->left->val;
    }
    q1.push(el->left);}
   if(el->right) q1.push(el->right);






    }

  return sum;
    }
};