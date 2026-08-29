class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int count=0;
        int found=0;

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }

                if(grid[i][j]==1) found++;
            }
        }

        int ans=0;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            ans=max(ans,t);
            for(int i=0;i<4;i++){
                int nx=r+dx[i];
                int nc=c+dy[i];

                if(nx>=0 && nc>=0 && nx<n && nc<m && !vis[nx][nc] && grid[nx][nc]==1){
                    q.push({{nx,nc},t+1});
                    vis[nx][nc]=1;
                    count++;
                }
            }
        }

        if(found !=count) return -1;
        return ans;
    }
};