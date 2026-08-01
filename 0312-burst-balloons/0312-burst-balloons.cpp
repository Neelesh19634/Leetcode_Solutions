class Solution {
    private:
    int solve(int i,int j, vector<int> &v,vector<vector<int>> &dp){
        if(i>j) return 0;
        int mina=INT_MIN;
        if (dp[i][j]!=-1) return dp[i][j];
        for(int k=i;k<=j;k++){
            int res=(v[i-1]*v[k]*v[j+1])+solve(i,k-1,v,dp)+solve(k+1,j,v,dp);

            mina=max(mina,res);
        }

        return dp[i][j]=mina;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2,vector<int> (n+2,-1));

        return solve(1,n,nums,dp);

    }
};