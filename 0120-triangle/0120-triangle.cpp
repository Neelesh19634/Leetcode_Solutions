class Solution {
    private:
    int solve(int i,int j,vector<vector<int>> &mat,vector<vector<int>> &dp,int n){
        if(dp[i][j]!=1e9) return dp[i][j];
        if(i==n-1) return mat[i][j];
        

        int left=mat[i][j]+solve(i+1,j,mat,dp,n);
        int dia=mat[i][j]+solve(i+1,j+1,mat,dp,n);

        return dp[i][j] =min(left,dia);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        

        vector<vector<int>> dp(n,vector<int>(n,1e9));

        return solve(0,0,triangle,dp,n);
    }
};