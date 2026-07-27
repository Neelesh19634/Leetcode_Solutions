class Solution {
    private:
    int solve(int i,int b, int cap,int n,vector<int> &v,vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(i==n) return 0;
        if(dp[i][b][cap]!=INT_MIN) return dp[i][b][cap];
         if(b){
            return dp[i][b][cap]= max(-v[i]+solve(i+1,0,cap,n,v,dp),solve(i+1,1,cap,n,v,dp));
        }

        return dp[i][b][cap]= max(v[i]+solve(i+1,1,cap-1,n,v,dp),solve(i+1,0,cap,n,v,dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,INT_MIN)));
        return solve(0,1,2,n,prices,dp);

    }
};