class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int l = 0; l < n; l++) {
            int ans = INT_MAX;
            int mina = INT_MAX;

            for (int r = l; r < n; r++) {
                ans &= nums[r];
                mina = min(mina, nums[r]);

                if (ans == mina) {
                    count++;
                }
            }
        }

        return count;
    }
};