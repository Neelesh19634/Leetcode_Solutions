class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto &it:tasks){
            mp[it]++;
        }

        priority_queue<int> q;

        for(auto &it:mp) q.push(it.second);
        
        int time=0;
        while(!q.empty()){
            // int count=0;
            int i=0;
            vector<int> temp;
            int cycle=n+1;

            while(i<cycle && !q.empty()){
                int x=q.top();
                q.pop();

                x--;
                if(x>0) temp.push_back(x);
                time++;
                i++;
                
            }

            for(auto &it:temp) q.push(it);

            if(q.empty()) break;

            time+=(cycle-i);
        }
        return time;
    }

};