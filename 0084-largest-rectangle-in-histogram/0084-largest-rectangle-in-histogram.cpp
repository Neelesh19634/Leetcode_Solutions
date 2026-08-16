class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        int maxa=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() &&(i==n || arr[st.top()]>arr[i])){
                int elem=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                
                maxa=max(maxa,(nse-pse-1)*arr[elem]);

            }
            st.push(i);
        }

       

        return maxa;
    }
};