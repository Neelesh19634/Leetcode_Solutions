class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dist(n,1e9);

        queue<pair<int,pair<int,int>>> q; //{dist,{node,stops}};

        dist[src]=0;
        q.push({0,{src,0}});

        while(!q.empty()){
            int dis=q.front().first;
            auto [node,stop]=q.front().second;
            q.pop();
            if(stop>k) continue;
            for(auto &it:adj[node]){
                int w=it.second;
                int newnode=it.first;
                if(dis+w<dist[newnode] && stop<=k){
                    dist[newnode]=dis+w;
                    q.push({dis+w,{newnode,stop+1}});
                }
            }

        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};