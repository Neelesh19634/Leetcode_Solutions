class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto com=[&](const pair<int,int> &a,const pair<int,int> &b){
            return a.second<b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(com)> q(com);

        unordered_map<int,int> mp;
        for(auto &it:nums) mp[it]++;

        for(auto &it:mp){
            q.push({it.first,it.second});
        }

        vector<int> ans;

        while(ans.size()<k){
            auto [x,f]=q.top();
            q.pop();
            ans.push_back(x);
        }

        return ans;
    }
};