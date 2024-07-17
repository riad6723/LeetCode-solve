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
    vector<TreeNode*> ans;
    bool shouldDelete[1010];

    void dfs(TreeNode* node, TreeNode* parent) {
        if(node == nullptr)return;
        if(parent == nullptr) {
            if(shouldDelete[node->val] == false) {
                ans.push_back(node);
                dfs(node->left,node);
                dfs(node->right,node);
            } else {
                dfs(node->left,nullptr);
                dfs(node->right,nullptr);
            }
        } else {
            if(shouldDelete[node->val] == false) {
                dfs(node->left,node);
                dfs(node->right,node);
            } else {
                dfs(node->left,nullptr);
                dfs(node->right,nullptr);
                if(parent->left != nullptr and parent->left->val == node->val)parent->left = nullptr;
                if(parent->right != nullptr and parent->right->val == node->val)parent->right = nullptr;
            }
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        memset(shouldDelete,false,sizeof(shouldDelete));
        for(auto x: to_delete)shouldDelete[x] = true;
        dfs(root,nullptr);
        return ans;
    }
};
