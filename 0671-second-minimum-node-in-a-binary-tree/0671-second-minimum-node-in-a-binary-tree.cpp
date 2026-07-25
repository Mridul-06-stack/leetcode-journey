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
    int findSecondMinimumValue(TreeNode* root) {
       set<int> ans;
        queue<TreeNode*> q1;
        if(!root){
            return -1;
        }
        q1.push(root);
        while(!q1.empty()){
            int size=q1.size();
           
            for(int i=0;i<size;i++){
                TreeNode* el=q1.front();
                q1.pop();
               ans.insert(el->val);
                if(el->left) q1.push(el->left);
                if(el->right) q1.push(el->right);

            }
            
        }
    auto it=ans.begin();
    if(ans.size()!=1){
        it++;
        return *it;
    }
    
   return -1; }
};