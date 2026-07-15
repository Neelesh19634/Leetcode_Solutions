class Solution {
    private:
    bool solve(int i,int target,vector<int> &mat,vector<vector<int>> &dp){
        if(target==0) return true;
        if(i==0) return mat[i]==target;

        if(dp[i][target]!=-1) return dp[i][target];

        bool nt=solve(i-1,target,mat,dp);
        bool t=false;
        if(mat[i]<=target){
            t=solve(i-1,target-mat[i],mat,dp);
        }

        return dp[i][target]=(t||nt);
    }
    
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(auto &it:nums){
            ans+=it;
        }

        if(ans%2) return false;
        vector<vector<int>> dp(n,vector<int>(ans+1,-1));

        return solve(n-1,ans/2,nums,dp);
    }
};