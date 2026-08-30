class Solution {
    //dfs(i,j,n,m,dx,dy,grid,vis);
    private:
    void dfs(int i,int j,int n,int m ,int dx[],int dy[],vector<vector<int>> &grid ,vector<vector<int>> &vis){
        vis[i][j]=1;

        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];

            if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
                dfs(nx,ny,n,m,dx,dy,grid,vis);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==0 || m==0) return 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j]){
                dfs(0,j,n,m,dx,dy,grid,vis);
            }
            if(grid[n-1][j]==1 && !vis[n-1][j]){
                dfs(n-1,j,n,m,dx,dy,grid,vis);
            }
        }

        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(i,0,n,m,dx,dy,grid,vis);
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                dfs(i,m-1,n,m,dx,dy,grid,vis);
            } 
        }

        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1) count++;
            }
        }

        return count;
    }
};