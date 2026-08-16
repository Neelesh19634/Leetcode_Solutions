class Solution {
    private:
    int findarea(vector<int> &arr){
        int n=arr.size();
        stack<int> st;
        int maxa=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || arr[st.top()]>arr[i])){
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
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int maxa=0;
        vector<int> ans(m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='1') ans[j]++;
                else ans[j]=0;
            }
            int area=findarea(ans);
            maxa=max(maxa,area);
        }

        return maxa;
    }
};