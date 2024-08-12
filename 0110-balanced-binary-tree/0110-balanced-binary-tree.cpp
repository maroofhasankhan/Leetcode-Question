
class Solution {
public:
int depth(TreeNode* root){
        if(!root)return 0;

        int left=depth(root->left);
        int right=depth(root->right);
        if (abs(left-right)>1)return -5000;
        return max(left,right)+1;
}

    bool isBalanced(TreeNode* root) {
        if(depth(root)<0){
            return false;
        }
        return true;
    }
};