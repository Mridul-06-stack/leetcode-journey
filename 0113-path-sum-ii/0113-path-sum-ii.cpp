/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void find(TreeNode* root, vector<vector<int>>& ans, vector<int>& temp,
              int currentsum, int targetsum) {
        if (!root) {
            return;
        }
            temp.emplace_back(root->val);
            currentsum+=root->val;
        if (root->left == NULL && root->right == NULL) {
            if (currentsum == targetsum) {
                ans.emplace_back(temp);
              
            } 
             temp.pop_back();
            return;
        }
    
       
        
        find(root->left, ans, temp, currentsum, targetsum);
        find(root->right, ans, temp, currentsum, targetsum);
        temp.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int currentsum = 0;
        find(root, ans, temp, currentsum, targetSum);
        return ans;
    }
};