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
    TreeNode* findlast(TreeNode* root){
        while(root && root->right){
            root=root->right;
        }
        return root;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;

        TreeNode* rc=root->right;
        TreeNode* lc=findlast(root->left);
        lc->right=rc;

        return root->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;

        if(root->val==key){
            return helper(root);
        }

        TreeNode* temp=root;;
        while(temp!=NULL){
            if(temp->val>key){
                if(temp->left && temp->left->val==key){
                    temp->left=helper(temp->left);
                    break;
                }else
                {
                    temp=temp->left;
                }
            }else{
                if(temp->right && temp->right->val==key){
                    temp->right=helper(temp->right);
                    break;
                }else
                {
                    temp=temp->right;
                }
            
            
            }

        }
            return root;
    }
};