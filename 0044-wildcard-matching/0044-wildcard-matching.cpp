class Solution {
    bool ans(string &p,int j){
        for(int i=0;i<=j;i++){
            if(p[i]!='*') return false;
        }

        return true;
    }
    bool solve(int i,int j,string &s,string &p,vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;

        if(i<0 && j>=0) return ans(p,j);

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=solve(i-1,j-1,s,p,dp);

        }
        if(p[j]=='*'){
            return dp[i][j]=(solve(i-1,j,s,p,dp) || solve(i,j-1,s,p,dp));
        }

        return false;
    }
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return solve(n-1,m-1,s,p,dp);
    }
};