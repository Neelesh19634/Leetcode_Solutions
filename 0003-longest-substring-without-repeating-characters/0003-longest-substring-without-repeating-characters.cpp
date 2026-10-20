class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;

        int n=s.size();
        int l=0;
        int r=0;
        int maxa=0;
       while(r<n){
        if (mp.find(s[r]) != mp.end()) {
                l = max(l, mp[s[r]] + 1);
            

        }
            int len=r-l+1;
            maxa=max(maxa,len);
            mp[s[r]]=r;
            r++;
        

        
       }

        return maxa;
    }
};