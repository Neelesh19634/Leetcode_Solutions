class Solution {
    private:
     void merge(int l,int h,int mid,vector<int> &arr){
        vector<int> temp;
        int left=l;
        int right=mid+1;

        while(left<=mid && right<=h ){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=h){
            temp.push_back(arr[right]);
            right++;
        }

        for(int i=l;i<=h;i++){
            arr[i]=temp[i-l];
        }
     }

     int cnt(int l,int h,int mid,vector<int> &arr){
        int right=mid+1;
        int count=0;

        for(int i=l;i<=mid;i++){
            while(right <= h &&
               (long long)arr[i] > 2LL * arr[right]) right++;

            count+=(right-(mid+1));
        }

        return count;
     }
    private:
    int msort(int l,int h,vector<int> &arr){
        int ans=0;
        if(l>=h) return ans;

        int mid=l+(h-l)/2;

        ans+=msort(l,mid,arr);
         ans+=msort(mid+1,h,arr);
         ans+=cnt(l,h,mid,arr);
        merge(l,h,mid,arr);

        return ans;

    }
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return msort(0,n-1,nums);   
    }
};