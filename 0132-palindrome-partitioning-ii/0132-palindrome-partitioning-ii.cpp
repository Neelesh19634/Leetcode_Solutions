class Solution {
private:
    bool pal(int i, int j,const string &s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }
        return true;
    }

public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
         dp[n] = -1;
        for (int i = n - 1; i >= 0; i--) {
            int mina = INT_MAX;
            for (int j = i; j < n; j++) {
                if (pal(i, j, s)) {
                    int cost = 1 + dp[j + 1];
                    mina = min(mina, cost);
                }
            }
            dp[i]=mina;
        }
        return dp[0];
    }
};