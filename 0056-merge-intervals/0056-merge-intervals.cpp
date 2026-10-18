class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        int n=in.size();

        vector<vector<int>> ans;
        sort(in.begin(),in.end());
        for(int i=0;i<n;i++){
            if(ans.empty() || ans.back()[1]<in[i][0]){
                ans.push_back(in[i]);
            }else{
                ans.back()[1]=max(in[i][1],ans.back()[1]);
            }
        }

        return ans;
    }
};