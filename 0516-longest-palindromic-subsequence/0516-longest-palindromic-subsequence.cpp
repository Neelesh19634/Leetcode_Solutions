class Solution {
    private:
    int solve(int i, int j,string &s,string &s2,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s2[j]) return dp[i][j]=1+solve(i-1,j-1,s,s2,dp);

        return dp[i][j]=max(solve(i-1,j,s,s2,dp),solve(i,j-1,s,s2,dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());

        int n=s.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return solve(n-1,n-1,s,s2,dp);
    }
};