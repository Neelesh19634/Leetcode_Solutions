class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n + 1, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans++;
                vis[i] = 1;
                queue<int> q;
                q.push(i);

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int it = 0; it < n; it++) {
                        if (adj[it][node] == 1 && !vis[it]) {
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }
            }
        }

        return ans;
    }
};