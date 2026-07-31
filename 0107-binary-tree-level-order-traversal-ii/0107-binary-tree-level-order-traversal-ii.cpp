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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int>> ans;
      if(!root) return ans;
      queue<TreeNode*> q1;
      q1.push(root);  
      vector<int> temp;
     while(!q1.empty()){
        int size=q1.size();
        temp.clear();
        for(int i=0;i<size;i++){
            TreeNode* el=q1.front();
            temp.push_back(el->val);
               q1.pop();
         if(el->left) q1.push(el->left);
         if(el->right) q1.push(el->right);


        }
        ans.emplace_back(temp);
     }
    
      int left=0;
      int right=ans.size()-1;
      while(left<right){
        swap(ans[left],ans[right]);
        left++;
        right--;
      }

    return ans;
    }
};