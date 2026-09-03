class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> dist(n,vector<int>(m,1e9));
        set<pair<int,pair<int,int>>> st;

        dist[0][0]=0;
        st.insert({0,{0,0}});

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        while(!st.empty()){
            auto it=*st.begin();
            int d=it.first;
            int r=it.second.first;
            int c=it.second.second;
            st.erase(it);
            if(r==n-1 && c==m-1) return d;
            for(int i=0;i<4;i++){
                int nr=r+dx[i];
                int nc=c+dy[i];

                if(nc>=0 && nr>=0 && nr<n && nc<m){
                    int nd=max(d,abs(mat[r][c]-mat[nr][nc]));
                    if(nd<dist[nr][nc]){
                        if(dist[nr][nc]!=1e9){
                            st.erase({dist[nr][nc],{nr,nc}});
                        }

                        dist[nr][nc]=nd;
                        st.insert({nd,{nr,nc}});
                    }
                }
            }

        }

        return dist[n-1][m=1];
    }
};