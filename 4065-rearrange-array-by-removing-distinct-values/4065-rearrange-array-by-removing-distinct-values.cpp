class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return {};

        vector<int> ans;

        while (!nums.empty()) {
            set<int> st;

            st.insert(nums.begin(), nums.end());

            for (auto& it : st) {
                ans.push_back(it);
                auto its = find(nums.begin(), nums.end(), it);
                nums.erase(its);
            }
            
        }

        return ans;
    }
};