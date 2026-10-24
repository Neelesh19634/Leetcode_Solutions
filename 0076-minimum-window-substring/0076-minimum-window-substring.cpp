class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<int> v(256,0);
        for(int i=0;i<m;i++){
            v[t[i]]++;
        }
        int start=-1;
        int l=0;
        int r=0;
        int mina=INT_MAX;
        int count=m;

        while(r<n){
            if(v[s[r]]>0) count--;
            v[s[r]]--;
            while(count==0){
                if(r-l+1<mina){
                    mina=r-l+1;
                    start=l;
                }
                v[s[l]]++;
                if(v[s[l]]>0) count++;
                l++;
            }
            r++;

        }
        return (start==-1)?"":s.substr(start,mina);

    }
};