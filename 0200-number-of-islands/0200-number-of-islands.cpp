class Solution {
    private:
    void dfs(int r,int c,int dx[],int dy[],vector<vector<char>> &grid ,vector<vector<int>> &vis,int n,int m){
        vis[r][c]=1;

        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];

            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]=='1'){
                dfs(nr,nc,dx,dy,grid,vis,n,m);
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
       
        vector<vector<int>> vis(n,vector<int>(m,0));
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                   
                    ans++;
                    dfs(i,j,dx,dy,grid,vis,n,m);
                 
                }
            }
        } 

        return ans;
    }
};