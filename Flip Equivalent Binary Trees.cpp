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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        //base case
        if(root1 == nullptr and root2 == nullptr) return true;
        if(root1 == nullptr or root2 == nullptr) return false;
        if(root1->val != root2->val) return false;

        bool left1 = flipEquiv(root1->left, root2->left);
        bool right1 = flipEquiv(root1->right, root2->right);
        bool left2 = flipEquiv(root1->left, root2->right);
        bool right2 = flipEquiv(root1->right, root2->left);

        if((left1 and right1) or (left2 and right2)) return true;
        return false;
    }
};
