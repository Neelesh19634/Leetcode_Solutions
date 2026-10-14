class Solution {
    private:
    int solve(int i,int p,int n,vector<int> &nums,vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][p+1]!=-1) return dp[i][p+1];

        int nt=solve(i+1,p,n,nums,dp);
        int t=INT_MIN;
        if(p==-1 || nums[i]>nums[p]){
            t=1+solve(i+1,i,n,nums,dp);
        }

        return dp[i][p+1]=max(t,nt);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));

        return solve(0,-1,n,nums,dp);
    }
};