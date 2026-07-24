class Solution {
    private:
    int solve(int i,int j,string &s, string &s1,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s1[j]) return dp[i][j]=1+solve(i-1,j-1,s,s1,dp);

        return dp[i][j]=max(solve(i-1,j,s,s1,dp),solve(i,j-1,s,s1,dp));
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        int len=n+m;

        vector<vector<int>> dp(n,vector<int> (m,-1));

        return len-2*solve(n-1,m-1,word1,word2,dp);
    }
};