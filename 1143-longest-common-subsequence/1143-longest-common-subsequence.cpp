class Solution {
    int solve(int i,int j,string &t1, string &t2,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(t1[i]==t2[j]) return dp[i][j]=1+solve(i-1,j-1,t1,t2,dp);
        return dp[i][j]=max(solve(i-1,j,t1,t2,dp),solve(i,j-1,t1,t2,dp));
    }
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n=t1.size();
        int m=t2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        return solve(n-1,m-1,t1,t2,dp);
    }
};