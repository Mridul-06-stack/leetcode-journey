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
class BSTIterator {

public:
 int idx=0;
 vector<int> inorder;
    BSTIterator(TreeNode* root) {
        
         find(root,inorder);
       
    }
    void  find(TreeNode* root, vector<int>& ans){
        if(!root)return;
        find(root->left,ans);
        ans.emplace_back(root->val);
        find(root->right,ans);
        return ;
    }
    int next() {
        int value=inorder[idx];
        idx++;
        return value;
    }
    
    bool hasNext() {
        return idx<inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */