class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n=lights.size();
        int m=arrivalTime.size();

        int maxa=*max_element(lights.begin(),lights.end());
        int ans=0;
        for(int i=0;i<m;i++){
            int r=arrivalTime[i]%period;

            if(r>=maxa){
                ans=max(ans,period-r);
            }
        }

        return ans;
    }
};