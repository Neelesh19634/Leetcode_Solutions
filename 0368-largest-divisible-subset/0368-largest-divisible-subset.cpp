class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();

        if(n==0) return {};
        sort(nums.begin(),nums.end());
        vector<int> dp(n+1,1);
        vector<int> hash(n);
        int maxa=1;
        int last=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }

            if(maxa<dp[i]){
                maxa=dp[i];
                last=i;
            }
        }


        vector<int> ans;
        ans.push_back(nums[last]);
        while(hash[last]!=last){
            last=hash[last];
            ans.push_back(nums[last]);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};