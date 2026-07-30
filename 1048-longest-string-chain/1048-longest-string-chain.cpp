class Solution {
    private:
    bool comp(string &a ,string &b){
        if(a.size()!=b.size()+1) return false;

        int i=0;
        int j=0;

        while(i<a.size()){

            if(a[i]==b[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }

        if(i==a.size() && j==b.size()) return true;
        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        auto com=[&](const string &a,const string &b){
            return a.size()<b.size();
        };
        sort(words.begin(),words.end(),com);
        vector<int> dp(n+1,1);
        int maxa=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(comp(words[i],words[j]) && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }

            maxa=max(maxa,dp[i]);
        }

        return maxa;
    }
};