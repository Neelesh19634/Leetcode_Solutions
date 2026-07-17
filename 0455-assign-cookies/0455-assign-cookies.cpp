class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        int count=0;
        int n=s.size();
        for(int i=0;i<g.size();i++){
            if(n==0) break;

            auto it=lower_bound(s.begin(),s.end(),g[i]);

            if(it!=s.end()){
                n--;
                count++;
                s.erase(it);
            }
        }

        return count;
    }
};