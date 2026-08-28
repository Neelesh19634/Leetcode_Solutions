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
 class Node{
    public:
    int sum;
    int maxa;
    int mina;
    Node(int sum,int maxa,int mina) : sum(sum),maxa(maxa),mina(mina){}
 };



class Solution {
    private:
    int ans=0;
    Node solve(TreeNode* root){
        if(!root) return Node(0,INT_MIN,INT_MAX);
        int res=0;

        auto left=solve(root->left);
        auto right=solve(root->right);

        if(left.maxa<root->val && root->val<right.mina){
            res=left.sum+right.sum+root->val;
            ans=max(ans,res);

            return Node(res,max(root->val,right.maxa),min(root->val,left.mina));

        }

        return Node(0,INT_MAX,INT_MIN);
        
    }
public:
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};