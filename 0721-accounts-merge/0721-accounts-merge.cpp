class Solution {
    vector<int> rank,parent;
    int findp(int i){
        if(i==parent[i]) return i;

        return parent[i]=findp(parent[i]);
    }

    void dsu(int i,int j){
        int pi=findp(i);
        int pj=findp(j);

        if(pi==pj) return;

        if(rank[pi]<rank[pj]){
            parent[pi]=pj;
        }else if(rank[pj]<rank[pi]){
            parent[pj]=pi;
        }
        else{
            parent[pi]=pj;
            rank[pj]++;
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        rank.resize(n,0);
        parent.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        unordered_map<string,int> mp;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }else{
                    dsu(i,mp[mail]);
                }
            }
        }

        vector<vector<string>> res(n);

        for(auto &it:mp){
            string mail=it.first;
            int node=findp(it.second);
            res[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i=0;i<n;i++){
            if(res[i].size()==0) continue;
            sort(res[i].begin(),res[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(auto &it:res[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }
        return ans;
    }
};