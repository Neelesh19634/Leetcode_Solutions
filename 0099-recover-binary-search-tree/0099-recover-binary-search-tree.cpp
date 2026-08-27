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
    TreeNode* first,*last,*middle,*prev;
    private:
    void solve(TreeNode* root){
        if(root==NULL) return;
        solve(root->left);
        if(prev!=NULL && (root->val<prev->val)){
            if(first==NULL) {
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        solve(root->right);
        
    }
public:
    void recoverTree(TreeNode* root) {
        if(root==NULL) return ;

        first=NULL,last=NULL,middle=NULL;

        prev=new TreeNode(INT_MIN);

        solve(root);

        if(first && last) swap(first->val,last->val);
        else swap(first->val,middle->val);
    }
};