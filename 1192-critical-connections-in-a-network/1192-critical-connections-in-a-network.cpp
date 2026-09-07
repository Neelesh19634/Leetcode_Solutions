class Solution {
    int timer = 1;
    // dfs(0,-1,low,tin,ans,vis,adj);
private:
    void dfs(int node, int parent, vector<int>& low, vector<int>& tin,
             vector<vector<int>>& ans, vector<int>& vis,
             vector<vector<int>>& adj) {
        vis[node] = 1;
        low[node] = timer;
        tin[node] = timer;
        timer++;
        for (auto& it : adj[node]) {
            if (it == parent)
                continue;
            if (!vis[it]) {
                dfs(it, node, low, tin, ans, vis, adj);

                low[node] = min(low[it], low[node]);

                if (low[it] > tin[node]) {
                    ans.push_back({node, it});
                }
            } else {
                low[node] = min(low[it], low[node]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> low(n, 0), tin(n, 0);
        vector<vector<int>> ans;
        vector<int> vis(n, 0);
        dfs(0, -1, low, tin, ans, vis, adj);

        return ans;
    }
};