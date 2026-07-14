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
    void find(TreeNode *root,string temp,vector<string> & ans){
    if(!root) return ;
    if(!temp.empty())
    {
   temp += "->";
temp += to_string(root->val);}
    else{
        temp+=(to_string(root->val));
    }
     if(root->left==NULL&& root->right==NULL){
        ans.emplace_back(temp);
        while(!temp.empty()&&temp.back()!='-'){
            temp.pop_back();
        }
        if(!temp.empty())
        temp.pop_back();
        
     }
     find(root->left,temp,ans);
     find(root->right,temp,ans);
     while(!temp.empty()&&temp.back()!='-'){
            temp.pop_back();
        }
         if(!temp.empty())
        temp.pop_back();
    return ;


   }
    vector<string> binaryTreePaths(TreeNode* root) {
    string  temp;
    vector<string> ans;
    find(root,temp,ans);
    return ans;
    }
};