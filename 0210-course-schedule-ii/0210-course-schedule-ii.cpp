class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for(auto &it:edges){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }

        queue<int> q;
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto &it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }

        if(ans.size()!=n) return {};

        return ans;
    }


};