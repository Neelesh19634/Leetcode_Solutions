/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
    void findparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp){
        if(root==NULL) return;

        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(node->left){
                mp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right]=node;
                q.push(node->right);
            }
        }
    }

    void solve(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp,TreeNode* target,int k,vector<int> &ans){
        if(root==NULL) return ;

        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> vis;
        int curr=0;

        q.push(target);
        vis[target]=true;
        while(!q.empty()){
            int len=q.size();
            if(curr++==k) break;
            for(int i=0;i<len;i++){
                auto node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    vis[node->left]=true;
                    q.push(node->left);
                }

                if(node->right && !vis[node->right]){
                    vis[node->right]=true;
                    q.push(node->right);
                }
                if(mp.count(node) && !vis[mp[node]]){
                    vis[mp[node]]=true;
                    q.push(mp[node]);
                }
            }
        }

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       vector<int> ans;
       if(!root) return ans;
       unordered_map<TreeNode*, TreeNode*> mp;
        findparent(root,mp);

        solve(root,mp,target,k,ans);
        return ans;

        
    }
};