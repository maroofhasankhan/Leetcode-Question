class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)return true;

        if(!p && q)return false;

        if(p && !q)return false;
        
        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        bool val =(p->val==q->val);

        if(left && right && val)return true;
        else{
            return false;
        }
    }
};