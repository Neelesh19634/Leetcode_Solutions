class Solution {
    private:
    int solve(int i,int n,int k,vector<int> &arr,vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int len=0,maxa=0,res=0;

        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxa=max(maxa,arr[j]);
            int m=(len*maxa)+solve(j+1,n,k,arr,dp);
            res=max(res,m);
        }

        return dp[i]=res;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return solve(0,n,k,arr,dp);
    }
};