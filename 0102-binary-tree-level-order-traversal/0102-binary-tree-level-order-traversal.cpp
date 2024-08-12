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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        q.push(NULL);
        vector <int>vec;

        while(q.size()>1){
            TreeNode* temp=q.front();
            q.pop();

            if(!temp){
                ans.push_back(vec);
                vec.clear();
                q.push(NULL);
            }else{
            vec.push_back(temp->val);
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
            }
        }
         if (!vec.empty()) {
            ans.push_back(vec);
        }
        return ans;
    }
};