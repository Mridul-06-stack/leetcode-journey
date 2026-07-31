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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root) return ans;
        queue<TreeNode*> q1;
        q1.push(root);
        while(!q1.empty()){
           double size=q1.size();
            double sum=0;
            
            for(int i=0;i<size;i++){
                TreeNode* el=q1.front();
                q1.pop();
               sum+=el->val;
               if(el->left) q1.push(el->left);
               if(el->right) q1.push(el->right);
            }
            ans.push_back(sum/size);

        }
   return ans; }
};