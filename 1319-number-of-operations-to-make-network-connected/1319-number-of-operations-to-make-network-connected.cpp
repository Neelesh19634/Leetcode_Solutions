class Solution {
    vector<int> parent,rank;
    private:
    int findp(int i){
        if(i==parent[i]) return i;
        return parent[i]=findp(parent[i]);
    }

    void dsu(int i, int j){
        int pi=findp(i);
        int pj=findp(j);
        if(pi==pj) return;

        if(rank[pi]<rank[pj]){
            parent[pi]=pj;
        }
        else if(rank[pj]<rank[pi]){
            parent[pj]=pi;
        }else{
            parent[pj]=pi;
            rank[pi]++;
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        

        parent.resize(n+1);
        rank.resize(n+1,0);
        if(edges.size()<n-1) return -1;

        for(int i=0;i<n;i++) parent[i]=i;

        for(auto &it:edges){
            dsu(it[0],it[1]);
        }
        set<int> st;

        for(int i=0;i<n;i++){
            st.insert(findp(i));
        }

        return st.size()-1;
        
    }
};