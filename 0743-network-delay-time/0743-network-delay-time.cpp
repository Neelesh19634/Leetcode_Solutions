class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }

        set<pair<int,int>> st;
        vector<int> dist(n+1,INT_MAX);

        st.insert({0,k});
        dist[k]=0;

        while(!st.empty()){
            auto it=*st.begin();
            st.erase(it);
            auto [d,node]=it;

            for(auto &jt:adj[node]){
                int newnode=jt.first;
                int c=jt.second;

                if(c+d<dist[newnode]){
                    if(dist[newnode]!=1e9) {
                        st.erase({dist[newnode],newnode});

                    }
                    dist[newnode]=c+d;
                    st.insert({c+d,newnode});
                }
            }
        }
        
        int ans=*max_element(dist.begin()+1,dist.end());

        return ans==INT_MAX?-1:ans;
    }
};