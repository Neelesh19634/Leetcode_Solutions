class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& nv) {
      int n=v.size();
      vector<vector<int>> res;
        int i=0;
      while(i<n && v[i][1]<nv[0]) {
        res.push_back(v[i]);
        i++;

      } 
      while(i<n && v[i][0]<=nv[1]){
        nv[0]=min(nv[0],v[i][0]);
        nv[1]=max(nv[1],v[i][1]);
        i++;
      }
      res.push_back(nv);

      while(i<n){
        res.push_back(v[i]);
        i++;
      }

      return res;
    }
};