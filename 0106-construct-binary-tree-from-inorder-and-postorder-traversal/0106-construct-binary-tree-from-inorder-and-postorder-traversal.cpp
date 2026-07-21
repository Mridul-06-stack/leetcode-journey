/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int inStart, int inEnd,
                    int& postIndex,
                    unordered_map<int, int>& mp) {

        if (inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[postIndex--]);

        int pos = mp[root->val];

        // Build right subtree first
        root->right = build(inorder, postorder, pos + 1, inEnd, postIndex, mp);

        // Then build left subtree
        root->left = build(inorder, postorder, inStart, pos - 1, postIndex, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        int postIndex = postorder.size() - 1;

        return build(inorder, postorder, 0, inorder.size() - 1,
                     postIndex, mp);
    }
};