class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        long long base=0;

        for(int i=0;i<n;i++){
            if(i%2){
                base-=nums[i];
            }else{
                base+=nums[i];
            }
        }

        long long kadane=0;

        for(int p=0;p<=1;p++){
            long long curr=0;
            for(int i=p;i<n-1;i+=2){
                long long d=(long long)(nums[i+1]-nums[i]);
                if(p>0){
                    d=-d;
                }

                curr=max(d,curr+d);
                kadane=max(kadane,2*curr);
            }
        }

        return max(base,base+kadane);
    }
};