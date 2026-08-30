class Solution {
    //dfs(i,j,n,m,dx,dy,board,vis);

    private:
    void dfs(int i,int j, int n,int m ,int dx[],int dy[],vector<vector<char>> &board,vector<vector<int>> &vis){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];

            if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && board[nx][ny]=='O'){
                dfs(nx,ny,n,m,dx,dy,board,vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        if(n==0 || m==0) return;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && !vis[0][j]){
                dfs(0,j,n,m,dx,dy,board,vis);
            }

            if(board[n-1][j]=='O' && !vis[n-1][j]){
                dfs(n-1,j,n,m,dx,dy,board,vis);
            }
        }

        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i,0,n,m,dx,dy,board,vis);
            }

            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,n,m,dx,dy,board,vis);
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                   
                    board[i][j]='X';
                }
            }
        }

    }
};