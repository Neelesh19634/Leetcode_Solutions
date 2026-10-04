class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0]!=0 || grid[n-1][m-1]!=0) return -1;
        if(n==1 || m==1) return 1;

        vector<vector<int>> dist(n,vector<int> (m,1e9));
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        dist[0][0]=1;

        int dx[]={-1,-1,-1,0,1,1,1,0};
        int dy[]={-1,0,1,1,1,0,-1,-1};

        while(!q.empty()){
            int dis=q.front().first;
            auto [r,c]=q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int nr=r+dx[i];
                int nc=c+dy[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==0 && 1+dis<dist[nr][nc]){
                    dist[nr][nc]=1+dis;
                    
                    if(nr==n-1 && nc==m-1) return 1+dis;
                    q.push({1+dis,{nr,nc}});
                }
            }

        }
            return -1;
    }
};