class Solution {
    int profit=0;
    private:
    int solve(int i,int b,int n,vector<int> &p,vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][b]!=INT_MIN) return dp[i][b];

        if(b==0){
            profit=max(solve(i+1,0,n,p,dp),-p[i]+solve(i+1,1,n,p,dp));
        }else{
            profit=max(solve(i+1,1,n,p,dp),p[i]+solve(i+1,0,n,p,dp));
        }

        return dp[i][b]=profit;

        
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        vector<vector<int>>dp(n,vector<int>(2,INT_MIN));
        return solve(0,0,n,prices,dp);
    }
};