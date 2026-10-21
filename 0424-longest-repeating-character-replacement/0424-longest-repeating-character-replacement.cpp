class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0;
        int r=0;
        int size=0;
        map<int,int> mp;
        int maxa=0;
        while(r<n){
            mp[s[r]]++;
            size=max(size,mp[s[r]]);
            int len=r-l+1-size;
            if(len>k){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }else{
                maxa=max(maxa,r-l+1);
            }
            r++;
        }
        return maxa;
    }
};