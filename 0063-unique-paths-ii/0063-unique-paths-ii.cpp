class Solution {
    private:
    int solve(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &mat){
        if(i<0 || j<0) return 0;

        if(i==0 && j==0){
            if(mat[i][j]==1) return 0;
            else return 1;
        }
        if(mat[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int left=solve(i-1,j,dp,mat);
        int up=solve(i,j-1,dp,mat);

        return dp[i][j]=left+up;

    }
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n - 1, m - 1, dp, mat);
    }
};