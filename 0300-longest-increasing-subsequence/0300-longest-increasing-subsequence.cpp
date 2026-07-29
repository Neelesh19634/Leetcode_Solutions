class Solution {
    private:
    int solve(int i,int p,int n,vector<int> &v,vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][p+1]!=INT_MIN) return dp[i][p+1];
        int nt=solve(i+1,p,n,v,dp);
        int t=INT_MIN;
        if(p==-1 || v[i]>v[p]){
            t=1+solve(i+1,i,n,v,dp);
        }

        return dp[i][p+1]=max(nt,t);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MIN));
        return solve(0,-1,n,nums,dp);
    }
};