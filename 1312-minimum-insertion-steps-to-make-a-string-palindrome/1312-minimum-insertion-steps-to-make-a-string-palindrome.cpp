class Solution {
private:
    int solve(int i, int j, string& s, string& s1, vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s1[j])
           return dp[i][j] = 1 + solve(i - 1, j - 1, s, s1, dp);

        return dp[i][j] = dp[i][j] =
                   max(solve(i - 1, j, s, s1, dp), solve(i, j - 1, s, s1, dp));
        ;
    }

    public : 
    int minInsertions(string s) {
        int n = s.size();

        string s1 = s;
        reverse(s1.begin(), s1.end());

        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = solve(n - 1, n - 1, s, s1, dp);
        return n - ans;
    }
};