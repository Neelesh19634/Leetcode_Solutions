class Solution {
    private:
    int solve(int i,int tar,vector<int> &nums,vector<vector<int>> &dp){
        if(i==0){
            if(tar==0 && nums[i]==tar) return 2;
            if(tar==0 || nums[i]==tar) return 1;
            return 0; 
        }

        if(dp[i][tar]!=-1) return dp[i][tar];
        int nt=solve(i-1,tar,nums,dp);
        int t=0;
        if(nums[i]<=tar){
            t=solve(i-1,tar-nums[i],nums,dp);
        }

        return dp[i][tar]=(t+nt);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int res=0;

        for(auto &it:nums){
            res+=it;
        }

        if((res-target) %2) return 0;
        if(target>res) return 0;

        int k=(res-target)/2;

        vector<vector<int>> dp(n,vector<int>(k+1,-1));

        return solve(n-1,k,nums,dp);

    }
};