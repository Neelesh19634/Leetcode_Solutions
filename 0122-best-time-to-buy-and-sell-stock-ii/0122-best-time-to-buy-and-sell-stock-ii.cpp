class Solution {
    int profit=0;
    int solve(int i,int b,int n,vector<int> &prices,vector<vector<int>> &dp){
        if(i==n) return 0;

        if(dp[i][b]!=INT_MIN) return dp[i][b];
        if(b){
            profit=max(-prices[i]+solve(i+1,0,n,prices,dp),solve(i+1,1,n,prices,dp));
        }else{
            profit=max(prices[i]+solve(i+1,1,n,prices,dp),solve(i+1,0,n,prices,dp));
        }

        return dp[i][b]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        vector<vector<int>> dp(n+1,vector<int>(2,INT_MIN));

        return solve(0,1,n,prices,dp);
    }
};