class Solution {
    private:
    int solve(int i,int b,int cap,int n,vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(i==n) return 0;
        if(dp[i][b][cap]!=INT_MIN) return dp[i][b][cap];
        if(b){
            return dp[i][b][cap]= max(-prices[i]+solve(i+1,0,cap,n,prices,dp),solve(i+1,1,cap,n,prices,dp));
        }

        return dp[i][b][cap]= max(prices[i]+solve(i+1,1,cap-1,n,prices,dp),solve(i+1,0,cap,n,prices,dp));
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,INT_MIN)));
        return solve(0,1,k,n,prices,dp);
    }
};