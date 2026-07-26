class Solution {
    private:
    int solve(int i,int j,string &a, string &b,vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]) return dp[i][j]=solve(i-1,j-1,a,b,dp);
        return dp[i][j]=min({1+solve(i-1,j,a,b,dp),1+solve(i,j-1,a,b,dp),1+solve(i-1,j-1,a,b,dp)});
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return solve(n-1,m-1,word1,word2,dp);
    }
};