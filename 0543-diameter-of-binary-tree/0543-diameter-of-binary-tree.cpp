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
int maxx=INT_MIN;
    int dia(TreeNode* root){
        if(!root)return 0;

        int left=dia(root->left);
        int right=dia(root->right);
        maxx=max(maxx,left+right);
        return max(left,right)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int n =dia(root);
        return maxx;
    }
};