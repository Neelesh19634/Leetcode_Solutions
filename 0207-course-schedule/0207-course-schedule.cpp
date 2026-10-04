class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto &it:edges){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        int count=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            count++;

            for(auto &it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        return count==n;
    }
};