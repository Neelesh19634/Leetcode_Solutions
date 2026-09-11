class Solution {
    private:
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j]=1+solve(i-1,j-1,s1,s2,dp);

        return dp[i][j]=max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp));
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        solve(n-1,m-1,str1,str2,dp);

        int i=n-1,j=m-1;
        string ans="";
        while(i>=0 && j>=0){
            int up=i>0?dp[i-1][j]:0;
            int left=j>0?dp[i][j-1]:0;

            if(str1[i]==str2[j]){
                ans+=str1[i];
                i--;
                j--;

            }
            else{
                if(i>0 && dp[i-1][j]==-1){
                    up=solve(i-1,j,str1,str2,dp);
                }
                if(j>0 && dp[i][j-1]==-1){
                    left=solve(i,j-1,str1,str2,dp);
                }

                if(up>=left){
                    ans+=str1[i];
                    i--;
                }else{
                    ans+=str2[j];
                    j--;
                }
            }
        }

        while(i>=0){
            ans+=str1[i];
            i--;
        }
        while(j>=0){
            ans+=str2[j];
            j--;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};