class Solution {
    vector<int> rank,parent;
    int findp(int i){
        if(i==parent[i]) return i;
        return parent[i]=findp(parent[i]);
    }

    void dsu(int i,int j){
        int pi=findp(i);
        int pj=findp(j);
        if(pi==pj) return ;
        if(rank[pi]<rank[pj]){
            parent[pi]=pj;
        }
        else if(rank[pj]<rank[pi]){
            parent[pj]=pi;
        }else
        {
            parent[pj]=pi;
            rank[pi]++;
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;

        for(auto &it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        int len=maxrow+maxcol;
        rank.resize(len+2,0);
        parent.resize(len+2,0);

        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }


        for(auto &it:stones){
            int r=it[0];
            int c=it[1]+maxrow+1;
            dsu(r,c);     
        }

        unordered_set<int> st;

        for(auto &it:stones){
            st.insert(findp(it[0]));
        }

        
        return n-st.size();
        
    }
};