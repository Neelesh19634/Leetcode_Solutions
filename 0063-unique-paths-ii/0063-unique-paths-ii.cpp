class Solution {
    private:
    int solve(int i,int j,vector<vector<int>> &mat,vector<vector<int>> &dp){
        if(i==0 && j==0){
            if(mat[i][j]!=1) return 1;
            return 0;
        };
        if(i<0 || j<0) return 0;
        if(mat[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int up=solve(i-1,j,mat,dp);

        int left=solve(i,j-1,mat,dp);

        return dp[i][j]=up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,mat,dp);
    }
};