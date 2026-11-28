class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        int l=0;
        int r=0;
        
        string left="";
        string right="";
        vector<vector<string>> ans;
        while(l<n && r<m){
            if(s1[l]!=s2[r]){
                left+=s1[l];
                right+=s2[r];
            }else{
                if(!left.empty() && !right.empty()){
                ans.push_back({left,right});
                }
                left="";
                right="";
            }
            l++;
            r++;

        }
        if(!left.empty() && !right.empty()){
                ans.push_back({left,right});
        }
        return ans;

    }
};