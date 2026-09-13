class Solution {
    int profit=0;
    private:
    int solve(int i,int b,int n, int cap,vector<int> &p,vector<vector<vector<int>>>&dp ){
        if(i==n || cap==0) return 0;

        if(dp[i][b][cap]!=INT_MIN) return dp[i][b][cap];

        if(b==0){
            profit=max(solve(i+1,0,n,cap,p,dp),-p[i]+solve(i+1,1,n,cap,p,dp));
        }else{
            profit=max(solve(i+1,1,n,cap,p,dp),p[i]+solve(i+1,0,n,cap-1,p,dp));
        }

        return dp[i][b][cap]=profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n==0 || k==0) return 0;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,INT_MIN)));

        return solve(0,0,n,k,prices,dp);
    }
};