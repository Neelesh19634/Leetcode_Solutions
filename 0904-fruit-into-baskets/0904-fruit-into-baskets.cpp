class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int r=0;
        int ans=0;
        map<int,int> mp;
        while(r<n){
            mp[arr[r]]++;
            if(mp.size()>2){
                mp[arr[l]]--;
                if(mp[arr[l]]==0) mp.erase(arr[l]);
                l++;
            }
            else{
                ans=max(ans,r-l+1);
            }
            r++;
        }

        return ans;
    }
};