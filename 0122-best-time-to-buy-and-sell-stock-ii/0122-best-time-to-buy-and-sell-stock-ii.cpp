class Solution {
    private:
     int profit=0;
    int solve(int i,int b,int n,vector<int> &v,vector<vector<int>> &dp){
        if(i==n) return 0;
       if(dp[i][b]!=INT_MIN) return dp[i][b];
        if(b){
            profit=max(-v[i]+solve(i+1,0,n,v,dp),solve(i+1,1,n,v,dp));
        }else{
            profit=max(v[i]+solve(i+1,1,n,v,dp),solve(i+1,0,n,v,dp));
        }

        return dp[i][b]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,INT_MIN));
        return solve(0,1,n,prices,dp);
    }
};