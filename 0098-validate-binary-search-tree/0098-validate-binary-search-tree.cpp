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
    private:
    bool solve(TreeNode* root ,long long maxa,long long mina){
        if(root==NULL) return true;

        if(root->val>=maxa || root->val<=mina) return false;

        return solve(root->left,root->val,mina) && solve(root->right,maxa,root->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root,LLONG_MAX,LLONG_MIN);
    }
};