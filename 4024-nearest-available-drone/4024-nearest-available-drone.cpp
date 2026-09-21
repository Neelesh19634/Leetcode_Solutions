class Solution {
public:
    int nearestDrone(vector<vector<int>>& d, vector<int>& t) {
        int n = d.size();
        int m = d[0].size();
        int mina=INT_MAX;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            int x = d[i][0];
            int y = d[i][1];
            int r = d[i][2];

            int dst = (abs(x - t[0]) + abs(y - t[1]));

            if (dst <= r && dst<mina) {
                mina=dst;
                idx=i;
            }
        }

        return idx;
    }
};