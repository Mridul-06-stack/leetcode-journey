/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

public:
    void mark_parent(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q1;

        q1.push(root);
         while (!q1.empty()) {
            int size = q1.size();
            for (int i = 0; i < size; i++) {
                TreeNode* el = q1.front();
                q1.pop();

                if (el->left) {
                    q1.push(el->left);
                    parent[el->left] = el;
                }
                if (el->right) {
                    q1.push(el->right);
                    parent[el->right] = el;
                }
            }
           
        }
         return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;

        mark_parent(root, parent);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q1;
        q1.push(target);
        visited[target] = true;
        int count = 0;
         while (!q1.empty()) {
            int size = q1.size();
            if (count == k) {
                break;
            }
            for (int i = 0; i < size; i++) {
                TreeNode* el = q1.front();
                q1.pop();
                if (el->left && !visited[el->left]) {
                    q1.push(el->left);
                    visited[el->left] = true;
                }
                if (el->right && !visited[el->right]) {
                    q1.push(el->right);
                    visited[el->right] = true;}

                    if (parent[el] && !visited[parent[el]]) {
                        q1.push(parent[el]);
                        visited[parent[el]] = true;
                    }
                    
                }count++;
            }
            vector<int> ans;
            while (!q1.empty()) {
                ans.emplace_back(q1.front()->val);
                q1.pop();
            }
            return ans;
        }
    };