class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true; // Empty tree is symmetric
        
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        
        q1.push(root->left);
        q2.push(root->right);
        
        while (!q1.empty() && !q2.empty()) {
            TreeNode* node1 = q1.front();
            TreeNode* node2 = q2.front();
            q1.pop();
            q2.pop();
            
            // Case 1: Both are null -> perfectly symmetric at this position, look at next items
            if (node1 == nullptr && node2 == nullptr) {
                continue; 
            }
            
            // Case 2: One is null and the other isn't -> structural asymmetry
            if (node1 == nullptr || node2 == nullptr) {
                return false;
            }
            
            // Case 3: Value mismatch -> value asymmetry
            if (node1->val != node2->val) {
                return false;
            }
            
            // Push children in mirrored order (it's completely safe to push nulls now)
            q1.push(node1->left);
            q1.push(node1->right);
            
            q2.push(node2->right);
            q2.push(node2->left);
        }
        
        return true;
    }
};