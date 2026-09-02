class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);

        for(int i=0;i<n;i++){
            for(auto &it:graph[i]){
                adj[it].push_back(i);
                indeg[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }


        while(!q.empty()){
            auto node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto &it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};