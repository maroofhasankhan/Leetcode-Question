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
vector<int>ans;
    void inoreder(TreeNode* root){
        if(root){
            inoreder(root->left);
            ans.push_back(root->val);
            inoreder(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inoreder(root);
        return ans;
    }
};