class Solution {
    private:
    bool solve(int i,int tar,vector<int> &nums,vector<vector<int>> &dp){
        if(tar==0) return true;
        if(i==0) return nums[i]==tar;
        if(dp[i][tar]!=-1) return dp[i][tar];

        bool nt=solve(i-1,tar,nums,dp);

        bool t=false;
        if(nums[i]<=tar){
            t=solve(i-1,tar-nums[i],nums,dp);
        }

        return dp[i][tar]=(t||nt);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int tot=0;
        for(int i=0;i<n;i++){
            tot+=nums[i];
        }


        if(tot%2) return false;
        int k= tot/2;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));

        return solve(n-1,k,nums,dp);
    }
};