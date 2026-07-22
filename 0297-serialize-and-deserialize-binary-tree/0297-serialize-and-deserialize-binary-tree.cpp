/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if (!root) return "";

        queue<TreeNode*> q1;
        q1.push(root);

        string ans;

        while (!q1.empty()) {

            TreeNode* el = q1.front();
            q1.pop();

            if (el) {
                ans += to_string(el->val) + ",";
                q1.push(el->left);
                q1.push(el->right);
            }
            else {
                ans += "#,";
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if (data.empty()) return NULL;

        stringstream st(data);
        string str;

        getline(st, str, ',');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q1;
        q1.push(root);

        while (!q1.empty()) {

            TreeNode* el = q1.front();
            q1.pop();

            // Left Child
            getline(st, str, ',');

            if (str != "#") {
                TreeNode* leftnode = new TreeNode(stoi(str));
                el->left = leftnode;
                q1.push(leftnode);
            }

            // Right Child
            getline(st, str, ',');

            if (str != "#") {
                TreeNode* rightnode = new TreeNode(stoi(str));
                el->right = rightnode;
                q1.push(rightnode);
            }
        }

        return root;
    }
};