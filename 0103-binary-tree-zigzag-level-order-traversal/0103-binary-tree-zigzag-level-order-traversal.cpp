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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       
        bool flip=true;
        vector<vector<int>> ans;
        if(root==NULL) return ans;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){

            int len=q.size();

            vector<int> temp(len);

            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                q.pop();
                int idx=flip?i:len-1-i;
                temp[idx]=node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            flip=!flip;
            ans.push_back(temp);
        }

        return ans;
    }
};