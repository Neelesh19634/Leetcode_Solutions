class Solution {
    private:
    int solve(int i,int b,int n,int fee,vector<int> &prices,vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][b]!=INT_MIN) return dp[i][b];
        if(b){
            return dp[i][b]= max(-prices[i]+solve(i+1,0,n,fee,prices,dp),solve(i+1,1,n,fee,prices,dp));
        }

        return dp[i][b]= max(prices[i]+solve(i+1,1,n,fee,prices,dp)-fee,solve(i+1,0,n,fee,prices,dp));
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,INT_MIN));
        return solve(0,1,n,fee,prices,dp);
    }
};