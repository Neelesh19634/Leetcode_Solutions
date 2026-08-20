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
    void parentmap(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp){
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

    vector<int> solve(TreeNode* root,TreeNode* target,int k ,unordered_map<TreeNode*,TreeNode*> &mp){
        queue<TreeNode*> q;
        unordered_set<TreeNode*> st;
        
        q.push(target);
        st.insert(target);
        int curr=0;
        while(!q.empty()){
            int len=q.size();
            if(curr++==k) break;

            for(int i=0;i<len;i++){
                auto node=q.front();
                q.pop();

                if(node->left && st.find(node->left)==st.end()){
                    q.push(node->left);
                    st.insert(node->left);
                }

                if(node->right && st.find(node->right)==st.end()){
                    q.push(node->right);
                    st.insert(node->right);
                }

                if(mp.count(node) && st.find(mp[node])==st.end()){
                    q.push(mp[node]);
                    st.insert(mp[node]);
                }
            }
        }

        vector<int> res;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            res.push_back(node->val);
        }

        return res;
        

    }
public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL) return {};
        unordered_map<TreeNode*,TreeNode*> mp;
        parentmap(root,mp);

        return solve(root,target,k,mp);
    }
};