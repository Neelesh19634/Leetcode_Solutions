class Solution {
    private:
        int solve(int i,int tar,vector<int> &mat,vector<vector<int>> &dp){
            if(i==0) return dp[i][tar]=(tar%mat[i]==0);
            if(dp[i][tar]!=-1) return dp[i][tar];

            int nt=solve(i-1,tar,mat,dp);

            int t=0;
            if(mat[i]<=tar){
                t=solve(i,tar-mat[i],mat,dp);
            }

            return dp[i][tar]=(t+nt);
        }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};