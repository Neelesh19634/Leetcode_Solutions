class KthLargest {
    priority_queue<int,vector<int>,greater<int>> q;
    int n;
public:
    KthLargest(int k, vector<int>& nums) {
        n=k;
        for(auto &it:nums){
            q.push(it);
            if(q.size()>k) q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size()>n) q.pop();

        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */