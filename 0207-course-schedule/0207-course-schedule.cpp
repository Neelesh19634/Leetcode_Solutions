class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n ,0);
        for(auto &it:edges){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }

        queue<int> q;
       int count=0;

        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }

        while(!q.empty()){
            auto node=q.front();
            q.pop();
           count++;

            for(auto &it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }

        return count==n;
    }
};