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
    bool match(TreeNode* root, TreeNode* subRoot) {
        
        if(root!=NULL && subRoot!=NULL){
            bool a= match(root->left, subRoot->left); 
            bool b= match(root->right, subRoot->right); 

            if((root->val==subRoot->val) && a  && b)return true;
            else 
                return false;
        }
        else if(root==nullptr && subRoot==nullptr){
            return true;
        }
        else 
            return false;
    }

    bool ans=false;
    void inOrder(TreeNode* root, TreeNode* subRoot){
        if(root!=nullptr){
            inOrder(root->left,subRoot);
            bool x=match(root ,subRoot);
            if(x)ans=x;
            inOrder(root->right,subRoot);
            
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot){
        inOrder(root,subRoot);
        return ans;
    }
};