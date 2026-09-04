class Solution {
    vector<int> parent,rank;
    int findp(int i){
        if(i==parent[i]) return parent[i];
        return parent[i]=findp(parent[i]);
    }

    void dsu(int i,int j){
        int pi=findp(i);
        int pj=findp(j);

        if(pi==pj) return;

        if(rank[pi]<rank[pj]){
            parent[pi]=pj;
        }
        else if(rank[pj]<rank[pi]){
            parent[pj]=pi;
        }else{
            parent[pi]=pj;
            rank[pj]++;
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        rank.resize(n+1,0);
        parent.resize(n);
        if(edges.size()<n-1) return -1;
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

       for(auto &it:edges){
        dsu(it[0],it[1]);
       }

       unordered_set<int> st;

       for(int i=0;i<n;i++){
        st.insert(findp(i));
       }

       return st.size()-1;
        
    }
};