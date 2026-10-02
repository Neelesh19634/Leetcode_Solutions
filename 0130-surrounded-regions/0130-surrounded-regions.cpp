class Solution {
    private:
    void dfs(int r,int c,vector<vector<int>> &vis,vector<vector<char>> &board,int dx[],int dy[],int n,int m){
        vis[r][c]=1;

        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]=='O' && !vis[nr][nc]){
                dfs(nr,nc,vis,board,dx,dy,n,m);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<m;i++){
            if(board[0][i]=='O') {
                dfs(0,i,vis,board,dx,dy,n,m);
            }
            if(board[n-1][i]=='O'){
                dfs(n-1,i,vis,board,dx,dy,n,m);
            }
        }

        for(int i=0;i<n;i++){
            if(board[i][0]=='O') {
                dfs(i,0,vis,board,dx,dy,n,m);
            }
            if(board[i][m-1]=='O'){
                dfs(i,m-1,vis,board,dx,dy,n,m);
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};