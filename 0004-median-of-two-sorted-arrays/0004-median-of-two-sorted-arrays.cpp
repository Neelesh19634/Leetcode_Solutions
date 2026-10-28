class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int n=nums1.size();
        int m=nums2.size();
        int l=0;
        int h=n;
        while(l<=h){
            int c1=(l+h)/2;
            int c2=(n+m+1)/2-c1;

            int l1=c1==0?INT_MIN:nums1[c1-1];
            int l2=c2==0?INT_MIN:nums2[c2-1];

            int r1=c1==n?INT_MAX:nums1[c1];
            int r2=c2==m?INT_MAX:nums2[c2];

            if(l1<=r2 && l2<=r1){
                if((n+m)%2){
                    return max(l1,l2);
                }else{
                     return ((double)max(l1, l2) +
                            min(r1, r2)) / 2.0;
                }
            }
            else if(l1>r2){
                h=c1-1;
            }else {
                l=c1+1;
            }


        }

        return 0.0;
    }
};