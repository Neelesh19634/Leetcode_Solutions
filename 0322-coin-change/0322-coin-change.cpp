class Solution {
    private:
    int solve(vector<int> &coins,int tar,vector<int> &dp){
        if(tar==0) return 0;
        if(tar<0) return -1;
        if(dp[tar]!=-2) return dp[tar];

        int mina=INT_MAX;
        for(auto &it:coins){
            int res=solve(coins,tar-it,dp);
            if (res != -1) {
                mina = min(mina, res + 1);
            }
        }

        dp[tar]=(mina==INT_MAX)?-1:mina;

        return dp[tar];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
     
        vector<int> dp(amount+1,-2);

        return solve(coins,amount,dp);
    }
};