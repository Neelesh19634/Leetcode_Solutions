class Solution {
    int f(int left,int right , vector<int>&cit){
        int ans= 0; 
        int n = cit.size() ; 
        while(left<= right){
        int mid= left + (right - left)/2 ; 
        if(n- mid <= cit[mid]){
            ans = max(ans,n- mid) ; 
            right=mid-1 ; 
        }else{
            left = mid+1 ; 
        }

        }
        return ans ; 
    }
public:
    int hIndex(vector<int>& citations) {
        int n= citations.size() ; 
        return f(0, n-1, citations) ; 
    }
};