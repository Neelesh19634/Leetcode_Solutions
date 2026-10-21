class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int> v(3,-1);
        int count=0;
        for(int i=0;i<n;i++){
            v[s[i]-'a']=i;
            if(v[0] !=-1 && v[1]!=-1 && v[2]!=-1){
                count+=1+min({v[0],v[1],v[2]});
            }
        }

        return count;
    }
};