class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dist(n,1e9);
        queue<pair<int,pair<int,int>>> q; //{dis,{node,stops}}
        q.push({0,{src,0}});
        dist[src]=0;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int d=it.first;
            auto [node,stops]=it.second;

            if(stops>k) continue;

            for(auto jt:adj[node]){
                int newnode=jt.first;
                int c=jt.second;

                if(c+d <dist[newnode] && stops<=k){
                    dist[newnode]=c+d;
                    q.push({c+d,{newnode,stops+1}});
                }
            }
        }

        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};