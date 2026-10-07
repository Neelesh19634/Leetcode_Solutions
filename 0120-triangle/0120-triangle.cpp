class Solution {
    int solve(int i,int j,int n,vector<vector<int>>& tri,vector<vector<int>>& dp){
        if(i==n-1) return tri[i][j];
        if(dp[i][j]!=1e9) return dp[i][j];

        int left=tri[i][j]+solve(i+1,j,n,tri,dp);
        int dia=tri[i][j]+solve(i+1,j+1,n,tri,dp);

        return dp[i][j]=min(left,dia);
    }
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n=tri.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,1e9));

        return solve(0,0,n,tri,dp);
    }
};