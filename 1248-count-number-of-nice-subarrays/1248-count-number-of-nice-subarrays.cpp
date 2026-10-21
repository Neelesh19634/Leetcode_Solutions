class Solution {
    int solve(vector<int> &nums,int k){
         int n=nums.size();
         if(k<0) return 0;
        int l=0;
        int r=0;
        int count=0;
        int ans=0;
        while(r<n){
            if(nums[r]%2){
                count++;
            }
            while(count>k){
                if(nums[l]%2){

                count--;
                }
                l++;;
            }
            ans=ans+r-l+1;
            r++;
        }

        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       return solve(nums,k)-solve(nums,k-1);
    }
};