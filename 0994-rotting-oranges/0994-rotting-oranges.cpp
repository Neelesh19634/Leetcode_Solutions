class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        int found=0;
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
                if(grid[i][j]==1) found++;
            }
        }

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        int ans=0;
        while(!q.empty()){
            int timer=q.front().first;
            ans=max(ans,timer);
            auto [r,c]=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+dx[i];
                int nc=c+dy[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({timer+1,{nr,nc}});
                    count++;
                }
            }
        }

        if(found!=count) return -1;
        return ans;
    }
};