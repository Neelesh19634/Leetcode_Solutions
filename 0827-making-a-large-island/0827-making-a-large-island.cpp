class Solution {
    vector<int> parent,size;
    int findp(int i){
        if(i==parent[i]) return i;
        return parent[i]=findp(parent[i]);
    }

    void dsu(int i,int j){
        int pi=findp(i);
        int pj=findp(j);

        if(pi==pj) return;

        if(size[pi]<size[pj]){
            parent[pi]=pj;
            size[pj]+=size[pi];
        }else{
            parent[pj]=pi;
            size[pi]+=size[pj];
        }
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();

        parent.resize(n*n);
        size.resize(n*n,1);
        for(int i=0;i<n*n;i++) parent[i]=i;

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;

                for(int k=0;k<4;k++){
                    int nr=i+dx[k];
                    int nc=j+dy[k];

                    if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==1){
                        int node=i*n+j;
                        int adjnode=nr*n+nc;
                        dsu(node,adjnode);
                    }
                }
            }
        }

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;

                unordered_set<int> st;
                int res=0;
                for(int k=0;k<4;k++){
                    int nr=i+dx[k];
                    int nc=j+dy[k];
                    if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==1){
                       st.insert(findp(nr*n+nc));
                    }
                }
                for(auto &it:st){
                    res+=size[it];
                }
                ans=max(ans,res+1);

            }
        }
        for(int i=0;i<n;i++){
            ans=max(ans,size[findp(i)]);
        }


        return ans;
        
    }
};