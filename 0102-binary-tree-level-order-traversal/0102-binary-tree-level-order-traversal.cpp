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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
      vector<int> temp;
        vector<vector<int>> ans;
        
         if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            temp.clear();
            for(int i=0;i<size;i++){
                   TreeNode* el=q.front();
                   q.pop();
                   temp.push_back(el->val);
                   if(el->left)q.push(el->left);
                    if(el->right)q.push(el->right);


            }
            ans.push_back(temp);
        }



        return ans;
    }
};