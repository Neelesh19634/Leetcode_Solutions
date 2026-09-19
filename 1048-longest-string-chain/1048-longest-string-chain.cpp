class Solution {
    private:
    bool check(string &s1,string &s2){
        if(s1.size()!=s2.size()+1) return false;

        int i=0;
        int j=0;
        while(i<s1.size()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }

        if(s1.size()==i && j==s2.size()) return true;

        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        if(n==0) return 0;
        auto comp=[&](string &s1,string &s2){
            return s1.size()<s2.size();
        };
        sort(words.begin(),words.end(),comp);

        vector<int> dp(n+1,1);

        int maxa=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }

            if(dp[i]>maxa){
                maxa=dp[i];
            }
        }

        return maxa;

    }
};