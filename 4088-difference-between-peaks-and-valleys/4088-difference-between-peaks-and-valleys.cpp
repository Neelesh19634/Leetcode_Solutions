class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int n=nums.size();
        int sum1=0;
        int sum2=0;
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                sum1+=nums[i];
            }

            if(nums[i]<nums[i+1] && nums[i]<nums[i-1]){
                sum2+=nums[i];
            }
        }

        return sum1-sum2;
    }
};