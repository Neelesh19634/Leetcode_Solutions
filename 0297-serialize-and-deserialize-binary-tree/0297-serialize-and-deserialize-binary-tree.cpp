/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";

        queue<TreeNode*> q;
        string res="";

        q.push(root);

        while(!q.empty()){
            auto node=q.front();
            q.pop();

            if(node==NULL) res+="#,";
            else{

             res+=to_string(node->val)+",";

             q.push(node->left);
             q.push(node->right);
            }

            

        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

       
        stringstream s(data);
        string res;

        getline(s,res,',');

        TreeNode* root=new TreeNode(stoi(res));

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            auto node=q.front();
            q.pop();

            getline(s,res,',');

            if(res!="#"){
                TreeNode* l=new TreeNode(stoi(res));
                node->left=l;
                q.push(l);
            }

            getline(s,res,',');

            if(res!="#"){
                TreeNode* r=new TreeNode(stoi(res));
                node->right=r;
                q.push(r);
            }
            

        }

        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));