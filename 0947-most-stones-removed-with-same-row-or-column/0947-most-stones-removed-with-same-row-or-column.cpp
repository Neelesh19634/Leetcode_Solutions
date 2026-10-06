class Solution {
    vector<int> parent,rank;
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
        }else{
            parent[pj]=pi;
            rank[pi]++;
        }
    }
public:
    int removeStones(vector<vector<int>>& edges) {
        int n=edges.size();
        int maxrow=0;
        int maxcol=0;
           for(auto &it:edges){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }

        int len=maxrow+maxcol;
        parent.resize(len+2);
        rank.resize(len+2,0);

        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }

        

     
        for(auto &it:edges){
            int r=it[0];
            int c=it[1]+maxrow+1;

            dsu(r,c);
        }

        set<int> st;

        for(auto &it:edges){
            st.insert(findp(it[0]));
        }

        return n-st.size();
    }


};