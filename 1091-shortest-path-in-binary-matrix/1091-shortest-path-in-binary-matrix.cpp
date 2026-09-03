class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0] !=0 || grid[n-1][m-1]!=0) return -1;
        if(n==1 || m==1) return 1;

        vector<vector<int>> dist(n,vector<int> (m,1e9));
        queue<pair<int,pair<int,int>>> q;

        dist[0][0]=1;
        q.push({1,{0,0}});

        int dr[]={-1,-1,-1,0,1,1,1,0};
        int dc[]={-1,0,1,1,1,0,-1,-1};

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int d=it.first;
            int r=it.second.first;
            int c=it.second.second;

            for(int i=0;i<8;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==0 && 1+d<dist[nr][nc]){
                    dist[nr][nc]=1+d;

                    if(nr==n-1 && nc==m-1) return 1+d;
                    q.push({1+d,{nr,nc}});
                }
            }
        }

        return -1;

    }
};