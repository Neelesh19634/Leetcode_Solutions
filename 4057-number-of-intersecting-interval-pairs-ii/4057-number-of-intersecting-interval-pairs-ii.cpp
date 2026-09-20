class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0) return 0;
        sort(intervals.begin(), intervals.end());

        vector<int> ends;

        for(int i=0;i<n;i++){
            ends.push_back(intervals[i][1]);
        }

        sort(ends.begin(),ends.end());

        long long count=0;
        int j=0;
        for(int i=0;i<n;i++){
            while(j<n && ends[j]<intervals[i][0]){
                j++;
            }

            count+=i-j;
        }

        return count;
    }
};