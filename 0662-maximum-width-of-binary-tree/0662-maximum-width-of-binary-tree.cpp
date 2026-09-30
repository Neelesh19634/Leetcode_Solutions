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
    using ll=unsigned long long;
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        queue<pair<TreeNode*,int>> q;

        q.push({root,0});
        int maxa=0;
        while(!q.empty()){
            int size=q.size();
            int first=0;
            int last=0;
            int minidx=q.front().second;

            for(int i=0;i<size;i++){
                auto [node,idx]=q.front();
                q.pop();
                int curr=idx-minidx;

                if(i==0) first=curr;
                if(i==size-1) last=curr;

                if(node->left) q.push({node->left,2*curr+1});
                if(node->right) q.push({node->right,2*curr+2});

            }
            maxa=max(maxa,(int)(last-first+1));

            
        }
        return maxa;
    }
};