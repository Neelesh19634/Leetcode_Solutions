class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return {};
        sort(nums.begin(),nums.end());
        vector<int> dp(n+1,1),hash(n);

        int last=0;
        int maxa=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int p=0;p<i;p++){
                if(nums[i]%nums[p]==0 && dp[i]<dp[p]+1){
                    hash[i]=p;
                    dp[i]=1+dp[p];
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