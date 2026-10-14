class Solution {
    int profit=0;

    private:
    int solve(int i,int b,int cap,int n,vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(i==n || cap==0) return 0;
        if(dp[i][b][cap]!=INT_MIN) return dp[i][b][cap];

        if(b){
            profit=max(-prices[i]+solve(i+1,0,cap,n,prices,dp),solve(i+1,1,cap,n,prices,dp));
        }

        else{
            profit=max(prices[i]+solve(i+1,1,cap-1,n,prices,dp),solve(i+1,0,cap,n,prices,dp));
        }

        return dp[i][b][cap]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,INT_MIN)));

        return solve(0,1,2,n,prices,dp);
    }
};