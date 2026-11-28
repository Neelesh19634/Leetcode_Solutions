class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n=nums.size();
        int mina=INT_MAX;
        for(int i=0;i<n-1;i+=2){
            string res=to_string(nums[i])+to_string(nums[i+1]);
            mina=min(mina,stoi(res));
        }
        return mina;
    }
};