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
 void preorder(TreeNode *root,int row,int col,map<int ,map<int,multiset<int>>> &hash){
    if(!root) return ;
    hash[col][row].insert(root->val);
    //left
    preorder(root->left,row+1,col-1,hash);
    //right
    preorder(root->right,row+1,col+1,hash);
    
 }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       map<int ,map<int,multiset<int>>> hash;
       int row=0;
       int col=0;
       
       preorder(root,row,col,hash);
       vector<vector<int>> ans;
       for(auto it:hash){ 
        vector<int> temp;
        for(auto val: it.second){
            for(auto nodes:val.second)
            {
            temp.emplace_back(nodes);
            }
        }
        ans.emplace_back(temp);
       }

    return ans;    
    }
};