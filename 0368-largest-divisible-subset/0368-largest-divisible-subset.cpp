class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int> dp(n,1),hash(n);
        int last=0;
        int maxa=1;

        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int p=0;p<i;p++){
                if((arr[i]%arr[p]==0) && (1+dp[p]>dp[i])){
                    dp[i]=1+dp[p];
                    hash[i]=p;
                }
            }
            if(dp[i]>maxa){
                maxa=dp[i];
                last=i;
            }
        }

        vector<int> ans;
        ans.push_back(arr[last]);
        while(hash[last]!=last){
            last=hash[last];
            ans.push_back(arr[last]);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};