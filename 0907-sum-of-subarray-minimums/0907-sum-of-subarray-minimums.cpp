class Solution {
    const int mode=1e9+7;
    private:
    vector<int>  fnse(int n,vector<int> &arr){
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]) st.pop();

            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }

        return ans;

    }

    vector<int> fpse(int n,vector<int> &arr){
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]) st.pop();
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }

        return ans;
        
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        vector<int> pse=fpse(n,arr);
        vector<int> nse=fnse(n,arr);
        for(int i=0;i<n;i++){

        int left=i-pse[i];
        int right=nse[i]-i;

        ans=(ans + (1LL * arr[i] * left % mode) * right % mode) % mode;

        }

        return ans;

    }
};