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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q1;
        q1.push({root,0});
        int maxi=0;
        while(!q1.empty()){
            int size=q1.size();
            int minimum=q1.front().second;
            int start;
            int end;
            for(int i=0;i<size;i++){
                TreeNode *el=q1.front().first;
            
                int curr_idx=q1.front().second;
                q1.pop();
                if(i==0) start=curr_idx;
                if(i==size-1) end=curr_idx;
                if(el->left) q1.push({el->left,(long long)2*(curr_idx-minimum)+1});
                if(el->right) q1.push({el->right,(long long)2*(curr_idx-minimum)+2});
            }
         maxi=max(maxi,end-start+1);
        }

   return maxi;     
    }
};