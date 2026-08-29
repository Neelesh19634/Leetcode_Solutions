class Solution {
    private:
    void dfs(int sr,int sc, int n,int m,vector<vector<int>> &ans,int dx[],int dy[],int incolor,int newcolor,vector<vector<int>> &image){
        ans[sr][sc]=newcolor;

        for(int i=0;i<4;i++){
            int nr=sr+dx[i];
            int nc=sc+dy[i];

            if(nr>=0 && nc>=0 && nr<n && nc<m && ans[nr][nc]!=newcolor && image[nr][nc]==incolor){
                dfs(nr,nc,n,m,ans,dx,dy,incolor,newcolor,image);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int incolor=image[sr][sc];
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        vector<vector<int>> ans=image;

        dfs(sr,sc,n,m,ans,dx,dy,incolor,color,image);

        return ans;

    }
};