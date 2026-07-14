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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*,int>> q1;
        vector<int> ans;
        map<int,int> hash;
        if(!root){
            return ans;
        }
        q1.push({root,0});
        while(!q1.empty()){
            int size=q1.size();
            for(int i=0;i<size;i++){
                TreeNode *el=q1.front().first;
                int level=q1.front().second;
                hash[level]=el->val;
                q1.pop();
                if(el->left)  q1.push({el->left,level+1});
                if(el->right!=NULL) q1.push({el->right,level+1});

            }
        }
        for (auto &it:hash){
            ans.emplace_back(it.second);
        }
    return ans; }
};