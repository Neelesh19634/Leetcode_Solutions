class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        int n=in.size();
        auto comp=[&](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        };
        sort(in.begin(),in.end(),comp);
        int count=1;
        int last=in[0][1];
        for(int i=1;i<n;i++){
            if(in[i][0]>=last){
                count++;
                last=in[i][1];
            }
        }

        return n-count;
    }
};