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
 class Solve{
    stack<TreeNode*> st;
    bool reverse=true;
    public:
    void pushall(TreeNode* root){
        if(root==NULL) return;

        while(root!=NULL){
            st.push(root);
            if(reverse) root=root->right;
            else root=root->left;
        }
    }

    Solve(TreeNode* root,bool isreverse){
        reverse=isreverse;
        pushall(root);
    }

    bool hasnext(){ return !st.empty();}

    int next(){
        TreeNode* temp=st.top();
        st.pop();
        if(reverse) pushall(temp->left);
        else pushall(temp->right);

        return temp->val;
    }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;

        Solve l(root,false);
        Solve r(root,true);

        int i=l.next();
        int j=r.next();

        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }

        return false;
    }
};